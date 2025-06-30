from telebot import TeleBot, types
from telebot.handler_backends import State, StatesGroup
from telebot.storage import StateMemoryStorage

state_storage = StateMemoryStorage()
bot = TeleBot("YOUR_TOKEN_HERE", state_storage=state_storage)

class Form(StatesGroup):
    first_name = State()
    last_name = State()
    age = State()

@bot.message_handler(commands=['start'])
def start(message):
    bot.set_state(message.from_user.id, Form.first_name, message.chat.id)
    bot.send_message(message.chat.id, "What is your first name?")

@bot.message_handler(state=Form.first_name)
def get_firstname(message):
    with bot.retrieve_data(message.from_user.id, message.chat.id) as data:
        data['first_name'] = message.text
    bot.set_state(message.from_user.id, Form.last_name, message.chat.id)
    bot.send_message(message.chat.id, "What is your last name?")

@bot.message_handler(state=Form.last_name)
def get_lastname(message):
    with bot.retrieve_data(message.from_user.id, message.chat.id) as data:
        data['last_name'] = message.text
    bot.set_state(message.from_user.id, Form.age, message.chat.id)
    bot.send_message(message.chat.id, "How old are you?")

@bot.message_handler(state=Form.age)
def get_age(message):
    try:
        age = int(message.text)
    except:
        return bot.send_message(message.chat.id, "Invalid age!")

    with bot.retrieve_data(message.from_user.id, message.chat.id) as data:
        first = data['first_name']
        last = data['last_name']
        # Save to DB here...

    bot.send_message(message.chat.id, f"Saved: {first} {last}, age {age}")
    bot.delete_state(message.from_user.id, message.chat.id)

bot.polling()
