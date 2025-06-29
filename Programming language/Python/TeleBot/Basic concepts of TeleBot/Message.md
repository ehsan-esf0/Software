## 💬 What Is a `Message` in `telebot`?

A `Message` is an object that represents any kind of message sent in Telegram — text, photo, video, document, etc. When a user sends something to your bot, `telebot` gives it to you as a `Message` object.

---

## 🧩 Main Fields of the `Message` Object

Here are the most common and useful fields of a `Message` object:

| Field              | Type                   | Description                                |
| ------------------ | ---------------------- | ------------------------------------------ |
| `message_id`       | `int`                  | Unique ID of the message                   |
| `from_user`        | `User`                 | The sender of the message                  |
| `chat`             | `Chat`                 | The chat where the message came from       |
| `date`             | `datetime` (UNIX)      | When the message was sent                  |
| `text`             | `str`                  | The text content (if it's a text message)  |
| `photo`            | `list[PhotoSize]`      | List of available sizes of photo           |
| `document`         | `Document`             | A file/document sent                       |
| `video`            | `Video`                | A video sent                               |
| `voice`            | `Voice`                | A voice message (OPUS format)              |
| `audio`            | `Audio`                | An audio file (MP3, etc.)                  |
| `sticker`          | `Sticker`              | A sticker                                  |
| `animation`        | `Animation`            | A GIF animation                            |
| `location`         | `Location`             | A location (lat/lon)                       |
| `contact`          | `Contact`              | A contact card                             |
| `caption`          | `str`                  | Caption for media (photo/video/doc)        |
| `reply_to_message` | `Message`              | The message that was replied to            |
| `entities`         | `list[MessageEntity]`  | Contains formatting info (bold, URL, etc.) |
| `reply_markup`     | `InlineKeyboardMarkup` | Attached buttons (if any)                  |

---

## 🧪 Example: How to Read Fields from a Message

```python
@bot.message_handler(func=lambda message: True)
def handle_all_messages(message):
    print("Message ID:", message.message_id)
    print("From:", message.from_user.first_name)
    print("Chat ID:", message.chat.id)
    print("Message text:", message.text)
```

---

## ✍️ Message Formatting with `send_message`

You can send styled messages using Markdown or HTML:

```python
bot.send_message(chat_id, "*Bold text*", parse_mode='Markdown')
bot.send_message(chat_id, "<b>Bold</b>", parse_mode='HTML')
```

Available tags in **HTML**:

* `<b>`, `<i>`, `<u>`, `<s>`, `<code>`, `<pre>`, `<a href="URL">`

---

## 🎯 Replying to a Message

```python
bot.send_message(chat_id, "This is a reply", reply_to_message_id=message.message_id)
```

---

## 🎛️ Reply Markup (Buttons, Keyboards)

```python
markup = telebot.types.ReplyKeyboardMarkup(resize_keyboard=True)
markup.row("Option 1", "Option 2")
bot.send_message(chat_id, "Choose:", reply_markup=markup)
```

---

## 📌 Summary of `send_message()` Parameters

```python
bot.send_message(
    chat_id,                  # Who to send to
    text,                     # What to send
    parse_mode=None,          # 'HTML' or 'Markdown'
    disable_web_page_preview=False,
    disable_notification=False,
    reply_to_message_id=None,
    reply_markup=None,        # Buttons, keyboards, etc.
    entities=None
)
```

---

## 🔍 Example with All Parameters

```python
from telebot import types

markup = types.ReplyKeyboardMarkup(row_width=2)
markup.add(types.KeyboardButton("Option A"), types.KeyboardButton("Option B"))

bot.send_message(
    chat_id,
    "Choose an option:",
    parse_mode="HTML",
    disable_web_page_preview=True,
    reply_to_message_id=message.message_id,
    reply_markup=markup
)
```
