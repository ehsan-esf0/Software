To **send a document (file)** to a user using `telebot`, you can use the method:

```python
bot.send_document(chat_id, document)
```

---

### ✅ Example: Send a Local File (like PDF, TXT, ZIP)

```python
import telebot

bot = telebot.TeleBot("YOUR_BOT_TOKEN")

@bot.message_handler(commands=['senddoc'])
def send_document_example(message):
    with open("example.pdf", "rb") as file:
        bot.send_document(message.chat.id, file)

bot.infinity_polling()
```

📝 **Explanation:**

* `"example.pdf"` is a local file in your script's folder.
* `"rb"` opens the file in binary read mode.
* `message.chat.id` gets the ID of the user who sent the message.

---

### 📎 Example: Send Document from a URL

```python
@bot.message_handler(commands=['sendurl'])
def send_document_from_url(message):
    file_url = "https://example.com/sample.pdf"
    bot.send_document(message.chat.id, file_url)
```

---

### 📂 Supported File Types

You can send:

* `.pdf`, `.docx`, `.txt`
* `.zip`, `.rar`
* `.csv`, `.xlsx`, `.json`
* Any file, up to Telegram's size limit (currently 50 MB for bots)

---

### 🎯 Tip: Add a Caption

```python
bot.send_document(message.chat.id, file, caption="Here is your document 📄")
```

