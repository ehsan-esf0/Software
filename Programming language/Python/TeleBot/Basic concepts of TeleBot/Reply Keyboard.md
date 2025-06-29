## 🎹 What Are Reply Keyboards?

**Reply keyboards** are the ones that **appear in the user’s typing area** (like a normal mobile keyboard). Unlike inline keyboards, when a button is pressed, the **text of the button is sent** to the bot as a normal message.

> They are great for guiding users in predefined choices.

---

## 🧱 Main Classes

* `ReplyKeyboardMarkup` – The full keyboard
* `KeyboardButton` – A single button

---

## ✅ Basic Example

```python
from telebot.types import ReplyKeyboardMarkup, KeyboardButton

@bot.message_handler(commands=['start'])
def send_welcome(message):
    markup = ReplyKeyboardMarkup(resize_keyboard=True, row_width=2)
    btn1 = KeyboardButton("👋 Say Hello")
    btn2 = KeyboardButton("📍 Send Location", request_location=True)
    btn3 = KeyboardButton("📞 Share Contact", request_contact=True)
    markup.add(btn1, btn2, btn3)

    bot.send_message(message.chat.id, "Choose an option:", reply_markup=markup)
```

---

## 📌 KeyboardButton Parameters

```python
KeyboardButton(
    text="Button Text",              # Required
    request_contact=True,            # Optional: Requests user's contact
    request_location=True            # Optional: Requests user's location
)
```

> ❗ Only one of `request_contact` or `request_location` should be used per button.

---

## 🎯 Customizing Keyboard Layout

You can organize buttons using:

* `.add(btn1, btn2)` → Auto wraps by `row_width`
* `.row(btn1, btn2)` → Manually sets one row
* `.add()` multiple times to stack vertically

### Example:

```python
markup = ReplyKeyboardMarkup(row_width=3)
btn1 = KeyboardButton("1")
btn2 = KeyboardButton("2")
btn3 = KeyboardButton("3")
btn4 = KeyboardButton("4")

markup.add(btn1, btn2, btn3)  # First row
markup.add(btn4)              # Second row
```

---

## 🧽 Remove or Hide Keyboard

You can **hide** or **remove** the keyboard using:

```python
from telebot.types import ReplyKeyboardRemove

# Remove the keyboard
bot.send_message(message.chat.id, "Keyboard removed", reply_markup=ReplyKeyboardRemove())
```

---

## 🧠 When to Use Reply Keyboards

Use reply keyboards when:

* You want **persistent choices** shown to the user
* You want to **replace** the mobile keyboard with predefined options
* You want to **ask for contact or location**

> Inline keyboards are better for advanced, dynamic, or inline actions (e.g., callback queries), while reply keyboards are better for input suggestions.

---

## 🧪 Example with Location and Contact

```python
@bot.message_handler(commands=['getinfo'])
def get_user_info(message):
    markup = ReplyKeyboardMarkup(resize_keyboard=True)
    markup.row(
        KeyboardButton("Send 📍 Location", request_location=True),
        KeyboardButton("Send 📞 Contact", request_contact=True)
    )
    bot.send_message(message.chat.id, "Please share your info:", reply_markup=markup)
```

You can then handle those using normal message handlers:

```python
@bot.message_handler(content_types=['location'])
def handle_location(message):
    location = message.location
    bot.send_message(message.chat.id, f"Lat: {location.latitude}, Lon: {location.longitude}")

@bot.message_handler(content_types=['contact'])
def handle_contact(message):
    contact = message.contact
    bot.send_message(message.chat.id, f"Phone: {contact.phone_number}")
```
