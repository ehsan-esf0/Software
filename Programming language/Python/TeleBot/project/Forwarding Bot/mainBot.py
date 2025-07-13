import telebot
from telebot.types import InlineKeyboardMarkup, InlineKeyboardButton

API_TOKEN = ''
CHANNEL_USERNAME = ''
REQUIRED_CHANNELS = []
bot = telebot.TeleBot(API_TOKEN)



@bot.channel_post_handler(content_types=[
    'text', 'photo', 'video', 'document', 'animation', 'sticker'
])
def handle_channel_post(message):
    message_id = message.message_id

    deep_link = f"https://t.me/{bot.get_me().username}?start={message_id}"

    print(f"New message: {message_id}")
    print(f"Deep link: {deep_link}")

    bot.send_message(
        CHANNEL_USERNAME,
        f"برای دریافت محتوا با ربات روی لینک زیر کلیک کنید:\n{deep_link}"
    )
    
def is_user_subscribed(user_id):
    for channel in REQUIRED_CHANNELS:
        try:
            member = bot.get_chat_member(chat_id=channel, user_id=user_id)
            if member.status in ['left', 'kicked']:
                return False
        except Exception as e:
            print(f"Error checking membership in {channel}: {e}")
            return False
    return True


@bot.message_handler(commands=['start'])
def handle_start(message):
    user_id = message.from_user.id
    args = message.text.split()

    if not is_user_subscribed(user_id):
        join_links = "\n".join([f"🔗 {ch}" for ch in REQUIRED_CHANNELS])
        bot.send_message(
            user_id,
            f"❌ برای دریافت فایل‌ها ابتدا باید عضو کانال‌های زیر شوید:\n\n{join_links}"
        )
        return

    if len(args) > 1:
        message_ids_str = args[1]
        message_ids = message_ids_str.split('_')

        success = True
        for mid_str in message_ids:
            try:
                mid = int(mid_str)
                bot.forward_message(
                    chat_id=user_id,
                    from_chat_id=CHANNEL_USERNAME,
                    message_id=mid
                )
            except Exception as e:
                bot.send_message(user_id, f"⚠️ خطا در ارسال پیام با id={mid_str}:\n{e}")
                success = False

        if success:
            bot.send_message(user_id, "✅ همه پیام‌ها با موفقیت ارسال شدند.")
    else:
        bot.send_message(user_id, "سلام! لطفا از طریق لینک ارسال شده در کانال وارد شوید.")


bot.infinity_polling()
