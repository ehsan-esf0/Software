## 📤 Full List of Sending Methods in `telebot`

| Content Type      | Method                                          | Description                            |
| ----------------- | ----------------------------------------------- | -------------------------------------- |
| 📝 Text           | `send_message(chat_id, text)`                   | Send a plain text message              |
| 📷 Photo          | `send_photo(chat_id, photo, caption=...)`       | Send a photo                           |
| 🎥 Video          | `send_video(chat_id, video)`                    | Send a video file                      |
| 🔊 Audio (music)  | `send_audio(chat_id, audio)`                    | Send an audio/music file               |
| 🎙️ Voice Message | `send_voice(chat_id, voice)`                    | Send a recorded voice message          |
| 🎞️ GIF           | `send_animation(chat_id, animation)`            | Send a GIF animation                   |
| 🗂️ Document      | `send_document(chat_id, document)`              | Send a document (PDF, ZIP, DOCX, etc.) |
| 🌍 Location       | `send_location(chat_id, latitude, longitude)`   | Send a geographic location             |
| 🧭 Venue          | `send_venue(chat_id, lat, lon, title, address)` | Send a location with title & address   |
| ☎️ Contact        | `send_contact(chat_id, phone, first_name)`      | Send a contact card                    |
| 😂 Sticker        | `send_sticker(chat_id, sticker)`                | Send a sticker                         |
| ⌨️ Chat Action    | `send_chat_action(chat_id, action)`             | Show typing / uploading status         |

---

## 📚 Examples of Each Type

### 1. 📝 Send Text Message

```python
bot.send_message(chat_id, "Hello, world!")
```

---

### 2. 📷 Send Photo

From a local file:

```python
with open('image.jpg', 'rb') as photo:
    bot.send_photo(chat_id, photo, caption="Nice photo!")
```

Or from a URL:

```python
bot.send_photo(chat_id, "https://example.com/image.jpg")
```

---

### 3. 🎥 Send Video

```python
with open('video.mp4', 'rb') as video:
    bot.send_video(chat_id, video)
```

---

### 4. 🔊 Send Audio

```python
with open('song.mp3', 'rb') as audio:
    bot.send_audio(chat_id, audio, title="My Song")
```

---

### 5. 🎙️ Send Voice Message

```python
with open('voice.ogg', 'rb') as voice:
    bot.send_voice(chat_id, voice)
```

---

### 6. 🎞️ Send GIF

```python
with open('funny.gif', 'rb') as gif:
    bot.send_animation(chat_id, gif)
```

---

### 7. 📄 Send Document

```python
with open('file.pdf', 'rb') as doc:
    bot.send_document(chat_id, doc)
```

---

### 8. 🌍 Send Location

```python
bot.send_location(chat_id, latitude=35.6892, longitude=51.3890)
```

---

### 9. 🧭 Send Venue

```python
bot.send_venue(chat_id, 35.6892, 51.3890, "Azadi Tower", "Tehran, Iran")
```

---

### 10. ☎️ Send Contact

```python
bot.send_contact(chat_id, phone_number="+123456789", first_name="John")
```

---

### 11. 😂 Send Sticker

```python
with open('sticker.webp', 'rb') as sticker:
    bot.send_sticker(chat_id, sticker)
```

---

### 12. ⌨️ Show Chat Action (e.g. typing…)

```python
bot.send_chat_action(chat_id, 'typing')  # Other actions: upload_photo, record_video, etc.
```

---

## ✅ Important Notes

* Most files must be opened in binary mode using `'rb'`.
* Telegram bots have a max file size limit of **50 MB**.
* Use `message.chat.id` to get the `chat_id` inside a handler.
