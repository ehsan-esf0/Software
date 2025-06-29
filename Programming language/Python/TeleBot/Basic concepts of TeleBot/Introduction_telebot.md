## 📦 1. Installing the Library

You need to install `pyTelegramBotAPI` using pip:

```bash
pip install pyTelegramBotAPI
```

---

## 🔑 2. Get Your Bot Token

Go to [@BotFather](https://t.me/BotFather) on Telegram and create a new bot. It will give you a **token** like this:

```python
TOKEN = '123456789:ABCdefGHIjklMNOpqrSTUvwxYZ'
```

---

## 🤖 3. Create the Bot

```python
import telebot

bot = telebot.TeleBot(TOKEN)
```

---

## 🟢 4. Handle `/start` Command

```python
@bot.message_handler(commands=['start'])
def send_welcome(message):
    bot.reply_to(message, "Hello! I'm your friendly Telegram bot 😊")
```

---

## 📝 5. Echo Any Message

```python
@bot.message_handler(func=lambda message: True)
def echo_all(message):
    bot.reply_to(message, message.text)
```

---

## 🚀 6. Start the Bot (Keep it Running)

```python
bot.infinity_polling()
```

---

## ✅ Full Working Example

```python
import telebot

bot = telebot.TeleBot("YOUR_BOT_TOKEN_HERE")

@bot.message_handler(commands=['start', 'help'])
def send_welcome(message):
    bot.reply_to(message, "Welcome! How can I help you?")

@bot.message_handler(func=lambda m: True)
def echo_all(message):
    bot.reply_to(message, message.text)

bot.infinity_polling()
```

---

## 🧠 Key Concepts Summary

| Concept                 | Description                               |
| ----------------------- | ----------------------------------------- |
| `TeleBot`               | The main bot object                       |
| `@message_handler(...)` | Decorator for handling messages           |
| `commands=['start']`    | Handles only the `/start` command         |
| `func=lambda m: True`   | Handles all types of text messages        |
| `reply_to()`            | Replies directly to the message           |
| `send_message()`        | Sends a message to a chat ID              |
| `infinity_polling()`    | Keeps the bot running (listening forever) |

