import telebot
import sqlite3

bot = telebot.TeleBot("YOUR_TOKEN_HERE")

conn = sqlite3.connect('users.db', check_same_thread=False)
cursor = conn.cursor()

cursor.execute('''
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY,
    first_name TEXT,
    last_name TEXT,
    age INTEGER
)
''')
conn.commit()

user_states = {}
user_data = {}

@bot.message_handler(commands=['start'])
def start(message):
    user_id = message.from_user.id
    user_states[user_id] = 'awaiting_first_name'
    bot.send_message(message.chat.id, "What's your first name?")

@bot.message_handler(func=lambda message: True)
def handle_all(message):
    user_id = message.from_user.id
    state = user_states.get(user_id)

    if state == 'awaiting_first_name':
        user_data[user_id] = {'first_name': message.text}
        user_states[user_id] = 'awaiting_last_name'
        bot.send_message(message.chat.id, "What's your last name?")

    elif state == 'awaiting_last_name':
        user_data[user_id]['last_name'] = message.text
        user_states[user_id] = 'awaiting_age'
        bot.send_message(message.chat.id, "How old are you?")

    elif state == 'awaiting_age':
        try:
            age = int(message.text)
            user_data[user_id]['age'] = age

            cursor.execute('''
                INSERT OR REPLACE INTO users (id, first_name, last_name, age)
                VALUES (?, ?, ?, ?)
            ''', (user_id, user_data[user_id]['first_name'],
                  user_data[user_id]['last_name'], age))
            conn.commit()

            bot.send_message(message.chat.id, "Thanks! Your data has been saved.")
            user_states.pop(user_id)
            user_data.pop(user_id)

        except ValueError:
            bot.send_message(message.chat.id, "Please enter a valid number for age.")

bot.polling()
