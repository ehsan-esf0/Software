## 🎛️ What Are Inline Keyboards?

Inline keyboards are buttons that appear **inside the message** (below the text), not replacing the user's typing area. Unlike normal keyboards, they **don’t disappear** and can send **callback queries** to the bot instead of sending a message.

---

## 🔧 Creating an Inline Keyboard

You need two classes:

* `InlineKeyboardMarkup` – The whole keyboard
* `InlineKeyboardButton` – A single button

### ✅ Basic Example:

```python
from telebot.types import InlineKeyboardMarkup, InlineKeyboardButton

@bot.message_handler(commands=['start'])
def send_welcome(message):
    markup = InlineKeyboardMarkup()
    btn1 = InlineKeyboardButton("Visit Website", url="https://example.com")
    btn2 = InlineKeyboardButton("Click Me", callback_data="button_clicked")
    markup.add(btn1, btn2)
    
    bot.send_message(message.chat.id, "Choose an option:", reply_markup=markup)
```

---

## 🧠 What is `callback_data`?

When a user clicks a button with `callback_data`, your bot receives a **callback query**. You can handle it like this:

```python
@bot.callback_query_handler(func=lambda call: True)
def handle_callback(call):
    if call.data == "button_clicked":
        bot.answer_callback_query(call.id, "You clicked the button!")
        bot.send_message(call.message.chat.id, "You clicked it.")
```

---

## 🔘 InlineKeyboardButton Parameters

```python
InlineKeyboardButton(
    text="Button label",            # Required
    url="https://...",              # Optional (for external link)
    callback_data="some_string",    # Optional (used in callback)
    switch_inline_query="...",      # Optional (start inline query)
    pay=True                        # Optional (for payments)
)
```

You cannot set both `url` and `callback_data` at the same time — pick **one**.

---

## 🧱 Arranging Buttons

You can control layout using `.add()` and `.row()`:

```python
markup = InlineKeyboardMarkup(row_width=2)
markup.add(
    InlineKeyboardButton("A", callback_data="a"),
    InlineKeyboardButton("B", callback_data="b"),
    InlineKeyboardButton("C", callback_data="c")
)
# A and B on one row, C on next row (if row_width=2)
```

Or manually:

```python
markup = InlineKeyboardMarkup()
markup.row(
    InlineKeyboardButton("Yes", callback_data="yes"),
    InlineKeyboardButton("No", callback_data="no")
)
markup.row(
    InlineKeyboardButton("Cancel", callback_data="cancel")
)
```

---

## 🔁 Editing Inline Keyboards

You can **edit** a message to change the inline keyboard or text:

```python
bot.edit_message_text(
    chat_id=call.message.chat.id,
    message_id=call.message.message_id,
    text="Updated message",
    reply_markup=new_markup
)
```

You can also remove the keyboard:

```python
bot.edit_message_reply_markup(chat_id=call.message.chat.id, message_id=call.message.message_id, reply_markup=None)
```

---

## 📦 Full Example

```python
@bot.message_handler(commands=['menu'])
def menu(message):
    markup = InlineKeyboardMarkup()
    markup.row(
        InlineKeyboardButton("Google", url="https://google.com"),
        InlineKeyboardButton("Say Hello", callback_data="hello")
    )
    bot.send_message(message.chat.id, "Choose:", reply_markup=markup)

@bot.callback_query_handler(func=lambda call: call.data == "hello")
def say_hello(call):
    bot.answer_callback_query(call.id, "Hello!")
    bot.send_message(call.message.chat.id, "Hi there!")
```