## 🌱 What is a `.env` file?

A `.env` file is a plain text file that stores **environment variables** — typically used for sensitive data and configuration values like:

* API tokens (e.g., Telegram bot token)
* Database URLs
* Debug settings
* Secret keys

### ✅ Why use a `.env` file?

| Reason         | Benefit                                      |
| -------------- | -------------------------------------------- |
| 🔒 Security    | Keeps secrets out of your codebase           |
| 🔁 Flexibility | Easily change config without touching code   |
| 🧪 Portability | Different values for dev, test, production   |
| 🧹 Clean Code  | Keeps config values out of your Python files |

---

## 🧾 Sample `.env` file

```env
BOT_TOKEN=123456:ABC-XYZ1234567890
DB_URL=postgresql://user:password@localhost:5432/mydb
DEBUG=True
```

You place this file in your project root, **but don't upload it to GitHub**. (Add it to `.gitignore`!)

---

## 🧰 Step-by-Step: Using `.env` in Python

### 1. Install `python-dotenv`

```bash
pip install python-dotenv
```

---

### 2. Create `.env` file

```env
# .env
BOT_TOKEN=987654:ABC-DEFGHIJK
DEBUG=True
```

---

### 3. Load it in your Python code (`config.py`)

```python
# config.py
import os
from dotenv import load_dotenv

load_dotenv()  # Loads .env into environment variables

BOT_TOKEN = os.getenv("BOT_TOKEN")
DEBUG = os.getenv("DEBUG", "False") == "True"
```

---

### 4. Use in your bot script (`bot.py`)

```python
# bot.py
from telebot import TeleBot
from config import BOT_TOKEN

bot = TeleBot(BOT_TOKEN)

@bot.message_handler(commands=['start'])
def handle_start(message):
    bot.send_message(message.chat.id, "Hello! I'm your bot 🤖")

bot.infinity_polling()
```

---

## 💡 Tip: Prevent `.env` from being committed

In your `.gitignore` file, add:

```
.env
```

This ensures your secrets don't get pushed to GitHub.

---

## 🧪 Full Project Example

### File Structure:

```
mybot/
├── bot.py
├── config.py
├── .env
├── .gitignore
└── requirements.txt
```

---

### `.env`

```env
BOT_TOKEN=123456789:ABCDEF-ghijkLMNOP
DEBUG=True
```

---

### `config.py`

```python
import os
from dotenv import load_dotenv

load_dotenv()

BOT_TOKEN = os.getenv("BOT_TOKEN")
DEBUG = os.getenv("DEBUG") == "True"
```

---

### `bot.py`

```python
from telebot import TeleBot
from config import BOT_TOKEN

bot = TeleBot(BOT_TOKEN)

@bot.message_handler(commands=['start'])
def greet(message):
    bot.send_message(message.chat.id, "Welcome!")

bot.infinity_polling()
```
