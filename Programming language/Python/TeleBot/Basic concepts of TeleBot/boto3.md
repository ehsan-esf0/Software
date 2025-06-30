## 📦 Requirements

### 1. Install required libraries:

```bash
pip install pyTelegramBotAPI boto3
```

---

## 🔐 AWS S3 Configuration

Either configure your AWS credentials in `~/.aws/credentials`, or use them directly in code like below:

```python
import boto3

s3 = boto3.client(
    's3',
    aws_access_key_id='YOUR_ACCESS_KEY',
    aws_secret_access_key='YOUR_SECRET_KEY',
    region_name='us-east-1'  # adjust to your AWS region
)

BUCKET_NAME = 'your-s3-bucket-name'
```

---

## 🤖 Complete Telegram Bot: Handle and Upload Files to S3

```python
import telebot
import boto3

API_TOKEN = 'YOUR_TELEGRAM_BOT_TOKEN'
bot = telebot.TeleBot(API_TOKEN)

# Connect to AWS S3
s3 = boto3.client(
    's3',
    aws_access_key_id='YOUR_ACCESS_KEY',
    aws_secret_access_key='YOUR_SECRET_KEY',
    region_name='us-east-1'
)

BUCKET_NAME = 'your-s3-bucket-name'

# Helper: Upload to S3
def upload_to_s3(file_bytes, filename):
    try:
        s3.put_object(Bucket=BUCKET_NAME, Key=filename, Body=file_bytes)
        return True
    except Exception as e:
        print("S3 Upload Error:", e)
        return False

# Handle all supported file types
@bot.message_handler(content_types=['photo', 'document', 'audio', 'video'])
def handle_file(message):
    file_info = None
    file_type = ''
    
    # Detect file type and get file info
    if message.content_type == 'photo':
        file_info = bot.get_file(message.photo[-1].file_id)
        file_type = 'photo'
    elif message.content_type == 'document':
        file_info = bot.get_file(message.document.file_id)
        file_type = 'document'
    elif message.content_type == 'audio':
        file_info = bot.get_file(message.audio.file_id)
        file_type = 'audio'
    elif message.content_type == 'video':
        file_info = bot.get_file(message.video.file_id)
        file_type = 'video'
    else:
        bot.reply_to(message, "❌ Unsupported file type.")
        return

    # Download the file from Telegram
    downloaded_file = bot.download_file(file_info.file_path)

    # Generate a filename: <type>/<user_id>_<original_filename>
    filename = f"{file_type}/{message.from_user.id}_{file_info.file_path.split('/')[-1]}"
    
    # Upload to S3
    success = upload_to_s3(downloaded_file, filename)

    if success:
        bot.reply_to(message, f"✅ Your {file_type} has been uploaded to cloud storage.")
    else:
        bot.reply_to(message, "❌ Failed to upload file to cloud.")

# Welcome message
@bot.message_handler(commands=['start'])
def send_welcome(message):
    bot.reply_to(message, "Hello! 📤 Send me any file and I will upload it to secure cloud storage (S3).")

print("Bot is running...")
bot.infinity_polling()
```

---

## 📁 File Structure on S3

Each file is saved under a folder based on its type and includes the user’s Telegram ID:

```
photo/12345678_image.jpg  
document/12345678_cv.pdf  
audio/12345678_voice.ogg  
video/12345678_clip.mp4  
```

---

## ✅ Benefits

* Supports **multiple content types**
* Organizes files by user and type
* Easily extendable for:

  * Download links
  * Image analysis
  * OCR (with Textract)
  * Voice-to-text
  * etc.
