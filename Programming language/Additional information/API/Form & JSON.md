# 📘 **Lesson 10: Sending Data to the Server with POST and PUT (Form & JSON)**

---

## 🔹 Part 1: What are POST and PUT?

| Method | Purpose    | Description                               |
| ------ | ---------- | ----------------------------------------- |
| POST   | **Create** | Send data to create a new resource        |
| PUT    | **Update** | Send data to completely update a resource |

---

## ✅ Two Common Ways to Send Data:

### 1. **Form Data** – like HTML forms

### 2. **JSON** – used in most modern APIs

---

## 🔸 1. **Sending Form Data**

### 📌 When to use:

* Traditional HTML forms
* `Content-Type: application/x-www-form-urlencoded`

---

### 👨‍💻 **Frontend (HTML Form Example)**

```html
<form action="/api/contact" method="POST">
  <input type="text" name="name" placeholder="Your name" />
  <input type="email" name="email" placeholder="Your email" />
  <textarea name="message" placeholder="Your message"></textarea>
  <button type="submit">Send</button>
</form>
```

This sends:

```
name=Ehsan&email=ehsan@example.com&message=Hello
```

Header:

```
Content-Type: application/x-www-form-urlencoded
```

---

### 👨‍🔧 **Backend (Flask)**

```python
from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/api/contact', methods=['POST'])
def contact():
    name = request.form['name']
    email = request.form['email']
    message = request.form['message']

    return jsonify({
        "success": True,
        "message": f"Message received from {name}"
    })
```

---

## 🔸 2. **Sending JSON Data**

### 📌 When to use:

* Modern frontend apps (React, Angular, etc.)
* Mobile apps
* API clients like Postman

Header:

```
Content-Type: application/json
```

---

### 👨‍💻 **Frontend (using fetch in JavaScript)**

```js
fetch('/api/contact', {
  method: 'POST',
  headers: {
    'Content-Type': 'application/json'
  },
  body: JSON.stringify({
    name: 'Ehsan',
    email: 'ehsan@example.com',
    message: 'Hello from frontend!'
  })
})
```

Or in **Postman**, send raw JSON:

```json
{
  "name": "Ehsan",
  "email": "ehsan@example.com",
  "message": "Hello from frontend!"
}
```

---

### 👨‍🔧 **Backend (Flask – reading JSON)**

```python
@app.route('/api/contact', methods=['POST'])
def contact():
    data = request.get_json()
    name = data['name']
    email = data['email']
    message = data['message']

    return jsonify({
        "success": True,
        "message": f"JSON received from {name}"
    })
```

---

## 🔸 Difference between Form and JSON

| Feature         | Form Data (`form`) | JSON (`application/json`)      |
| --------------- | ------------------ | ------------------------------ |
| Format          | key=value pairs    | Structured JSON format         |
| Read with Flask | `request.form`     | `request.get_json()`           |
| Use case        | Basic forms (HTML) | APIs, frontend JS, mobile apps |
| Structure       | Flat (no nesting)  | Nested, more flexible          |

---

## 🔸 Example – Create a New Product (POST)

**Request:**

```http
POST /api/products
Content-Type: application/json
```

**Body:**

```json
{
  "name": "Phone",
  "price": 850,
  "in_stock": true
}
```

**Response:**

```json
{
  "success": true,
  "message": "Product created",
  "data": {
    "id": 1,
    "name": "Phone",
    "price": 850,
    "in_stock": true
  }
}
```

---

## 🔸 Example – Update an Existing Product (PUT)

**Request:**

```http
PUT /api/products/1
Content-Type: application/json
```

**Body:**

```json
{
  "name": "Phone Pro",
  "price": 950,
  "in_stock": false
}
```

**Response:**

```json
{
  "success": true,
  "message": "Product updated",
  "data": {
    "id": 1,
    "name": "Phone Pro",
    "price": 950,
    "in_stock": false
  }
}
```

---

## 🔸 Summary: POST vs PUT

| Feature   | POST (Create)        | PUT (Update)                   |
| --------- | -------------------- | ------------------------------ |
| ID in URL | ❌ Not needed         | ✅ Required (e.g. `/product/1`) |
| Body      | Full new object      | Full updated object            |
| Effect    | Creates new resource | Replaces or updates resource   |

---
