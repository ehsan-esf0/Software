import telebot

bot = telebot.TeleBot("YOUR_BOT_TOKEN")

users = {}

@bot.message_handler(commands=['start'])
def start(message):
    user_id = message.from_user.id
    args = message.text.split()

    if user_id in users and users[user_id].get('step') == 'done':
        bot.send_message(user_id, f"👋 شما قبلاً ثبت‌نام کردید!\n🔗 لینک دعوت شما:\nhttps://t.me/{bot.get_me().username}?start={user_id}")
        return

    users[user_id] = {
        'step': 'ask_name',
        'name': '',
        'age': '',
        'city': '',
        'referrer': None,
        'points': 0
    }


    if len(args) > 1:
        try:
            referrer_id = int(args[1])
            if referrer_id != user_id and referrer_id in users:
                users[user_id]['referrer'] = referrer_id
        except:
            pass

    bot.send_message(user_id, "سلام! 😃 اول اسمتو بگو:")

@bot.message_handler(func=lambda message: message.from_user.id in users and users[message.from_user.id]['step'] != 'done')
def register_steps(message):
    user_id = message.from_user.id
    user = users[user_id]

    if user['step'] == 'ask_name':
        user['name'] = message.text.strip()
        user['step'] = 'ask_age'
        bot.send_message(user_id, "چند سالته؟")

    elif user['step'] == 'ask_age':
        user['age'] = message.text.strip()
        user['step'] = 'ask_city'
        bot.send_message(user_id, "اهل کدومی؟")

    elif user['step'] == 'ask_city':
        user['city'] = message.text.strip()
        user['step'] = 'done'
        bot.send_message(user_id, f"✅ ثبت‌نام کامل شد، {user['name']}! 🙌")


        ref = user['referrer']
        if ref and ref in users:
            users[ref]['points'] += 1
            bot.send_message(ref, f"🎉 یه نفر با لینک شما ثبت‌نام کرد!\nامتیاز جدید: {users[ref]['points']}")


        bot.send_message(user_id, f"🎁 اینم لینک دعوتت:\nhttps://t.me/{bot.get_me().username}?start={user_id}")

@bot.message_handler(commands=['points'])
def show_points(message):
    user_id = message.from_user.id
    points = users.get(user_id, {}).get('points', 0)
    bot.send_message(user_id, f"🏆 امتیاز شما: {points}")
