### ✅ **1. Import Libraries**

```python
import sqlite3
import telebot
```

---

### ✅ **2. Connect to SQLite3**

```python
conn = sqlite3.connect('my_database.db', check_same_thread=False)
cursor = conn.cursor()
```

> ⚠️ `check_same_thread=False` allows you to use the database across different threads — useful in Telegram bots.

---

### ✅ **3. Create a Table (Optional)**

Example: Create a `users` table:

```python
cursor.execute('''
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY,
    username TEXT,
    first_name TEXT
)
''')
conn.commit()
```

---

### ✅ **4. Set Up the Bot**

```python
bot = telebot.TeleBot('YOUR_BOT_TOKEN_HERE')
```

---

### ✅ **5. Handle `/start` Command and Save User Info**

```python
@bot.message_handler(commands=['start'])
def start_handler(message):
    user_id = message.from_user.id
    username = message.from_user.username
    first_name = message.from_user.first_name

    cursor.execute('INSERT OR IGNORE INTO users (id, username, first_name) VALUES (?, ?, ?)',
                   (user_id, username, first_name))
    conn.commit()

    bot.send_message(message.chat.id, f"Hello {first_name}, welcome!")
```

---

### ✅ **6. Start Polling**

```python
bot.polling()
```

---

### 💡 **Full Example**

```python
import sqlite3
import telebot

# Connect to DB
conn = sqlite3.connect('my_database.db', check_same_thread=False)
cursor = conn.cursor()

# Create users table
cursor.execute('''
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY,
    username TEXT,
    first_name TEXT
)
''')
conn.commit()

# Initialize bot
bot = telebot.TeleBot('YOUR_BOT_TOKEN_HERE')

# /start command handler
@bot.message_handler(commands=['start'])
def start_handler(message):
    user_id = message.from_user.id
    username = message.from_user.username
    first_name = message.from_user.first_name

    cursor.execute('INSERT OR IGNORE INTO users (id, username, first_name) VALUES (?, ?, ?)',
                   (user_id, username, first_name))
    conn.commit()

    bot.send_message(message.chat.id, f"Hello {first_name}, welcome!")

# Start polling
bot.polling()
```
