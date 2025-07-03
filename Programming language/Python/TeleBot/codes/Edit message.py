from telebot import TeleBot, types

bot = TeleBot("YOUR_BOT_TOKEN")

@bot.message_handler(commands=['start'])
def send_message(message):
    markup = types.InlineKeyboardMarkup()
    markup.add(types.InlineKeyboardButton("Edit Message", callback_data="edit"))
    bot.send_message(message.chat.id, "This is a test message.", reply_markup=markup)

@bot.callback_query_handler(func=lambda call: call.data == "edit")
def edit_message(call):
    bot.edit_message_text(
        chat_id=call.message.chat.id,
        message_id=call.message.message_id,
        text="🔄 The message has been edited!",
        reply_markup=None
    )

bot.infinity_polling()
