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

cursor.execute('''
CREATE TABLE IF NOT EXISTS user_states (
    user_id INTEGER PRIMARY KEY,
    state TEXT
)
''')

def set_state(user_id, state):
    cursor.execute("INSERT OR REPLACE INTO user_states (user_id, state) VALUES (?, ?)", (user_id, state))
    conn.commit()

def get_state(user_id):
    cursor.execute("SELECT state FROM user_states WHERE user_id=?", (user_id,))
    row = cursor.fetchone()
    return row[0] if row else None

@bot.message_handler(commands=['start'])
def start(message):
    set_state(message.from_user.id, 'awaiting_first_name')
    bot.send_message(message.chat.id, "What's your first name?")

@bot.message_handler(func=lambda message: True)
def handle_message(message):
    user_id = message.from_user.id
    state = get_state(user_id)

    if state == 'awaiting_first_name':
        cursor.execute("INSERT OR REPLACE INTO users (id, first_name) VALUES (?, ?)", (user_id, message.text))
        set_state(user_id, 'awaiting_last_name')
        bot.send_message(message.chat.id, "What's your last name?")

    elif state == 'awaiting_last_name':
        cursor.execute("UPDATE users SET last_name=? WHERE id=?", (message.text, user_id))
        set_state(user_id, 'awaiting_age')
        bot.send_message(message.chat.id, "How old are you?")

    elif state == 'awaiting_age':
        try:
            age = int(message.text)
            cursor.execute("UPDATE users SET age=? WHERE id=?", (age, user_id))
            cursor.execute("DELETE FROM user_states WHERE user_id=?", (user_id,))
            conn.commit()
            bot.send_message(message.chat.id, "All data saved successfully!")
        except ValueError:
            bot.send_message(message.chat.id, "Please enter a valid number.")

bot.polling()
