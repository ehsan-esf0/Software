# 🎯 Lesson 4: Working with Public APIs using Postman & Hoppscotch

---

## 🔖 **Step 1: Understanding Public APIs**

Public APIs provide free resources for practice or real app development.

Famous examples:

* JSONPlaceholder ([jsonplaceholder.typicode.com](https://jsonplaceholder.typicode.com))
* Reqres ([reqres.in](https://reqres.in))
* OpenWeather ([openweathermap.org](https://openweathermap.org))
* NewsAPI ([newsapi.org](https://newsapi.org))

---

## 🛠️ **Step 2: Detailed Introduction to Testing Tools**

### 🔸 **Postman**

* Powerful installable tool for API testing
* [https://www.postman.com/downloads](https://www.postman.com/downloads)

Steps:

1. Install and open Postman.
2. Click "New Request".
3. Choose method (GET, POST, etc.).
4. Enter URL and click **Send**.
5. Inspect response.

---

### 🔸 **Hoppscotch**

* Free, online, no installation required
* [https://hoppscotch.io](https://hoppscotch.io)

Steps:

1. Visit [hoppscotch.io](https://hoppscotch.io).
2. Select HTTP method (GET, POST, etc.).
3. Paste URL.
4. Click **Send** and inspect response.

---

## 📚 **Step 3: Detailed Practical Examples**

### 🔸 Example 1: Fetch Users (GET)

```
GET https://jsonplaceholder.typicode.com/users
```

* Test in Hoppscotch:

  1. Choose GET method.
  2. Paste URL and click Send.
  3. View JSON response.

---

### 🔸 Example 2: Fetch User by ID (id=3)

```
GET https://jsonplaceholder.typicode.com/users/3
```

* Steps:

  1. Select GET.
  2. Enter URL, send request.
  3. Check JSON response.

---

### 🔸 Example 3: Creating Data with POST

```
POST https://jsonplaceholder.typicode.com/posts
```

* Headers:

```
Content-Type: application/json
```

* Body:

```json
{
  "title": "New Post",
  "body": "Sample content for new post",
  "userId": 1
}
```

* Steps:

  1. Choose POST in Hoppscotch.
  2. Paste URL.
  3. Add Header (`Content-Type: application/json`).
  4. Add Body (JSON above).
  5. Send and view response.

---

## 📌 **Important Note:**

These APIs are mock services; data won't actually persist.

---

## 🧪 **Your Practice Exercises:**

Use Hoppscotch for these requests:

1. Get all comments:

```
GET https://jsonplaceholder.typicode.com/comments
```

2. Get comment number 10:

```
GET https://jsonplaceholder.typicode.com/comments/10
```

3. Create a new post (using POST).

Check the responses thoroughly.

