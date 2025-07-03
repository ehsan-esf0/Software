عالی! 🎯
حالا بریم سراغ **درس ششم: ساخت اولین API ساده**

در این درس یاد می‌گیری یک API ساده رو به‌صورت عملی و گام به گام با فریمورک **Flask** (پایتون) بسازی و تستش کنی.

مثل همیشه اول فارسی کامل و دقیق، بعد انگلیسی توضیح میدم.

---

# 🚀 درس ۶: ساخت اولین API ساده (فارسی)

برای ساخت اولین API از زبان برنامه‌نویسی پایتون و فریم‌ورک **Flask** استفاده می‌کنیم، چون ساده‌ترین روش برای شروع و فهمیدن مفاهیم اولیه API است.

---

## 🔧 مرحله اول: آماده کردن محیط

### گام ۱: نصب Python

اگر نداری از اینجا دانلود کن و نصبش کن:
[python.org/downloads](https://www.python.org/downloads/)

### گام ۲: نصب Flask

در ترمینال (CMD) دستور زیر رو بزن:

```bash
pip install flask
```

---

## 🔨 مرحله دوم: ایجاد اولین API ساده با Flask

یک پوشه ایجاد کن و داخلش فایل `app.py` رو بساز و کدهای زیر رو وارد کن:

**app.py**

```python
from flask import Flask, jsonify

app = Flask(__name__)

# تعریف مسیر اصلی
@app.route('/', methods=['GET'])
def home():
    return jsonify({"message": "سلام، این اولین API منه!"})

# اجرای برنامه
if __name__ == '__main__':
    app.run(debug=True)
```

---

## ▶️ مرحله سوم: اجرای API

* ترمینال رو باز کن.
* به پوشه پروژه برو.
* دستور زیر رو اجرا کن:

```bash
python app.py
```

* خروجی شبیه زیر خواهی دید:

```
* Running on http://127.0.0.1:5000
```

---

## 🌐 مرحله چهارم: تست API در مرورگر

حالا مرورگر رو باز کن و این آدرس رو بزن:

```
http://127.0.0.1:5000
```

* پاسخ JSON رو می‌بینی:

```json
{
  "message": "سلام، این اولین API منه!"
}
```

تبریک 🎉 تو اولین API رو ساختی!

---

## 🧪 مرحله پنجم: افزودن endpoint جدید

حالا بیا یه endpoint دیگه برای لیست کاربران اضافه کنیم:

کد جدید `app.py`:

```python
from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/', methods=['GET'])
def home():
    return jsonify({"message": "سلام، این اولین API منه!"})

@app.route('/users', methods=['GET'])
def users():
    users_list = [
        {"id": 1, "name": "علی"},
        {"id": 2, "name": "سارا"}
    ]
    return jsonify(users_list)

if __name__ == '__main__':
    app.run(debug=True)
```

* مجدد API رو اجرا کن:

```bash
python app.py
```

* حالا آدرس زیر رو تست کن:

```
http://127.0.0.1:5000/users
```

* پاسخ رو بررسی کن:

```json
[
  {"id": 1, "name": "علی"},
  {"id": 2, "name": "سارا"}
]
```

---

## 📌 تمرین عملی برای تو:

۱. یک endpoint جدید بساز به نام `/about` که پیام کوتاه درباره خودت برگردونه.
۲. API رو اجرا کن و endpoint جدید رو در مرورگر تست کن.

---

# 🚀 Lesson 6: Creating Your First Simple API (English)

In this lesson, we'll create a simple API using Python and the Flask framework, which is perfect for beginners.

---

## 🔧 Step 1: Environment Setup

### Step 1: Install Python

Download and install Python if you don't have it:
[python.org/downloads](https://www.python.org/downloads/)

### Step 2: Install Flask

Open terminal and run:

```bash
pip install flask
```

---

## 🔨 Step 2: Creating Your First Simple Flask API

Create a folder, then make a file named `app.py` with this code:

**app.py**

```python
from flask import Flask, jsonify

app = Flask(__name__)

# Define root route
@app.route('/', methods=['GET'])
def home():
    return jsonify({"message": "Hello, this is my first API!"})

# Run app
if __name__ == '__main__':
    app.run(debug=True)
```

---

## ▶️ Step 3: Running the API

* Open terminal.
* Navigate to your project folder.
* Run:

```bash
python app.py
```

* You'll see this output:

```
* Running on http://127.0.0.1:5000
```

---

## 🌐 Step 4: Testing the API in Browser

Open your browser and navigate to:

```
http://127.0.0.1:5000
```

* You'll see JSON response:

```json
{
  "message": "Hello, this is my first API!"
}
```

Congrats 🎉 You made your first API!

---

## 🧪 Step 5: Adding a New Endpoint

Let's add another endpoint to fetch users:

Updated `app.py`:

```python
from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/', methods=['GET'])
def home():
    return jsonify({"message": "Hello, this is my first API!"})

@app.route('/users', methods=['GET'])
def users():
    users_list = [
        {"id": 1, "name": "Ali"},
        {"id": 2, "name": "Sara"}
    ]
    return jsonify(users_list)

if __name__ == '__main__':
    app.run(debug=True)
```

* Run again:

```bash
python app.py
```

* Test in browser:

```
http://127.0.0.1:5000/users
```

* Check response:

```json
[
  {"id": 1, "name": "Ali"},
  {"id": 2, "name": "Sara"}
]
```

