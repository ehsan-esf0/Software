
### 1. JSON files

#### 📁 lang/en.json

```json
{
  "start": "Hello! Welcome 🌟",
  "help": "Commands: /start /help",
  "choose_language": "Please choose your language:"
}
```

#### 📁 lang/fa.json

```json
{
  "start": "سلام! خوش اومدی 🌟",
  "help": "دستورات: /start /help",
  "choose_language": "زبان خود را انتخاب کنید:"
}
```

---

### 2. Load messages (`translations.py`)

```python
import json

with open('lang/fa.json', encoding='utf-8') as f:
    fa = json.load(f)
with open('lang/en.json', encoding='utf-8') as f:
    en = json.load(f)

translations = {
    'fa': fa,
    'en': en
}

def t(key, lang='en'):
    return translations.get(lang, {}).get(key, key)
```

---

### 3. Store user language preference

```python
user_lang = {}  # e.g., user_lang[12345678] = 'en'
```

---

### 4. Example usage in `bot.py`

```python
from telebot import TeleBot, types
from translations import t, user_lang

bot = TeleBot("YOUR_BOT_TOKEN")

@bot.message_handler(commands=['start'])
def start_handler(message):
    chat_id = message.chat.id
    markup = types.InlineKeyboardMarkup()
    markup.add(
        types.InlineKeyboardButton("فارسی", callback_data="lang_fa"),
        types.InlineKeyboardButton("English", callback_data="lang_en")
    )
    bot.send_message(chat_id, t("choose_language", "en"), reply_markup=markup)

@bot.callback_query_handler(func=lambda call: call.data.startswith("lang_"))
def lang_selected(call):
    lang = call.data.split("_")[1]
    user_lang[call.from_user.id] = lang
    bot.send_message(call.message.chat.id, t("start", lang))

@bot.message_handler(commands=['help'])
def help_handler(message):
    lang = user_lang.get(message.from_user.id, 'en')
    bot.send_message(message.chat.id, t("help", lang))
```

