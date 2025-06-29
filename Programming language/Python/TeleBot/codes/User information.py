import telebot
from telebot.types import ReplyKeyboardMarkup, KeyboardButton, ReplyKeyboardRemove

# Initialize the bot with your token
bot = telebot.TeleBot("YOUR_BOT_TOKEN")  # Replace with your actual token

# Dictionary to temporarily store user data
user_data = {}

# Handler for /start command 
@bot.message_handler(commands=['start'])
def start(message):
    user_id = message.from_user.id
    user_data[user_id] = {}  # Initialize user data
    msg = bot.send_message(message.chat.id, "Hello! Please enter your name:")
    bot.register_next_step_handler(msg, get_name)  # Go to next step

# Step 1: Get user's name
def get_name(message):
    user_id = message.from_user.id
    user_data[user_id]['name'] = message.text

    # Create a button to request contact (phone number)
    markup = ReplyKeyboardMarkup(resize_keyboard=True)
    contact_btn = KeyboardButton("📞 Send Phone Number", request_contact=True)
    markup.add(contact_btn)

    msg = bot.send_message(message.chat.id, "Now please send your phone number:", reply_markup=markup)
    bot.register_next_step_handler(msg, get_contact)

# Step 2: Get user's phone number
def get_contact(message):
    user_id = message.from_user.id

    # Check if contact was sent via button or manually entered
    if message.contact:
        user_data[user_id]['phone'] = message.contact.phone_number
    else:
        user_data[user_id]['phone'] = message.text

    # Create a button to request location
    markup = ReplyKeyboardMarkup(resize_keyboard=True)
    location_btn = KeyboardButton("📍 Send Location", request_location=True)
    markup.add(location_btn)

    msg = bot.send_message(message.chat.id, "Now please send your location:", reply_markup=markup)
    bot.register_next_step_handler(msg, get_location)

# Step 3: Get user's location
def get_location(message):
    user_id = message.from_user.id

    # Check if location was sent or not
    if message.location:
        user_data[user_id]['location'] = f"{message.location.latitude}, {message.location.longitude}"
    else:
        user_data[user_id]['location'] = "Not received"

    # Remove custom keyboard
    bot.send_message(message.chat.id, "✅ Data received successfully.", reply_markup=ReplyKeyboardRemove())

    # Send summary of user information
    info = user_data[user_id]
    summary = f"""📝 Your Information:
👤 Name: {info['name']}
📞 Phone: {info['phone']}
📍 Location: {info['location']}
"""
    bot.send_message(message.chat.id, summary)

# Start polling to receive messages
bot.polling()
