# 📚 Lesson 3: Comprehensive Introduction to REST API (English)

---

## 🔖 What is REST API?

**REST (Representational State Transfer)** is a set of standards used to build APIs that are simple, understandable, and standardized. APIs that follow these standards are called **RESTful APIs**.

**REST’s Main Goal:**
Simplify communication, reduce complexity, and make requests and responses easy to read.

---

## 📌 Principles of REST APIs:

An API is RESTful when it follows these principles:

### 1. 🔹 **Client-Server**

The client (browser/mobile) and server are completely separate. The client sends requests, the server responds, both remain independent.

---

### 2. 🔹 **Stateless**

Each HTTP request is independent. The server does NOT remember previous requests.

* **Incorrect example:**
  Server remembers your previous requests.
* **Correct example:**
  Each request has all needed information.

---

### 3. 🔹 **Uniform Interface**

Requests must be standardized:

* Always use GET for retrieving data
* POST for creating data
* PUT for updating data entirely
* PATCH for partial updates
* DELETE for deleting resources

Example URL structure:

```
GET /users        ← get users list
GET /users/10     ← get user 10
POST /users       ← create new user
PUT /users/10     ← fully update user 10
PATCH /users/10   ← partially update user 10
DELETE /users/10  ← delete user 10
```

---

### 4. 🔹 **Resource-Based**

Everything in REST is considered a resource:

Examples:

* Users (`/users`)
* Products (`/products`)
* Orders (`/orders`)

Each resource has a clear URL:

```
/products
/products/123
/orders/567
```

---

### 5. 🔹 **JSON or XML for data transfer**

REST APIs usually use JSON or XML formats for transferring data:

Example JSON response:

```json
{
  "id": 1,
  "username": "ali",
  "email": "ali@example.com"
}
```

---

## 🛠️ **Real REST API Example:**

Imagine we have an API for a shop:

* Get all products:

```
GET https://api.shop.com/products
```

* Get product with ID 12:

```
GET https://api.shop.com/products/12
```

* Create new product:

```
POST https://api.shop.com/products
```

* Fully update product 12:

```
PUT https://api.shop.com/products/12
```

* Delete product 12:

```
DELETE https://api.shop.com/products/12
```

