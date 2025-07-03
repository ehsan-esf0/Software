# 📚 Comprehensive Introduction to HTTP

---

## 🔖 Detailed definition of HTTP:

**HTTP (HyperText Transfer Protocol)** is a set of rules and standards that allow **clients (like browsers or mobile apps)** to communicate with **servers (which store data and applications)**.

When you open a website, your browser sends an HTTP request, and the server responds by sending data in HTML, JSON, etc.

---

## 🔍 Detailed explanation of HTTP methods:

Every HTTP request specifies a method, instructing the server what action you want to perform.

| Method     | Precise Usage                             | Real-world Example                    |
| ---------- | ----------------------------------------- | ------------------------------------- |
| **GET**    | Retrieve data without changing the server | Getting a product list                |
| **POST**   | Create new data on the server             | User registration form submission     |
| **PUT**    | Replace entire existing data              | Completely updating a user profile    |
| **PATCH**  | Partially update existing data            | Updating only the user's phone number |
| **DELETE** | Delete data on the server                 | Removing a comment in social media    |

**Important notes:**

* GET method doesn't modify the server data.
* POST is commonly used to send new data to create resources.

---

## 📌 Status Codes with practical examples:

Responses include a status code indicating success or failure:

| Status                        | Precise Meaning           | Example                                |
| ----------------------------- | ------------------------- | -------------------------------------- |
| **200 OK**                    | Request succeeded         | Successfully loaded products           |
| **201 Created**               | New resource created      | Successfully registered new user       |
| **400 Bad Request**           | Your request is incorrect | Missing email in registration          |
| **401 Unauthorized**          | You must log in           | Trying to edit a profile without login |
| **403 Forbidden**             | You don't have permission | User accessing admin page              |
| **404 Not Found**             | Resource doesn't exist    | Opening non-existent page              |
| **500 Internal Server Error** | Server error              | Programming error on server            |

---

## 🛠️ HTTP request structure:

Every request consists of these parts:

1. **URL**

```
https://api.example.com/users
```

2. **Method**

```
GET
```

3. **Headers**

```
Content-Type: application/json
Authorization: Bearer <token>
```

4. **Body** (for POST, PUT, PATCH)

```json
{
  "username": "ali",
  "email": "ali@example.com"
}
```

* GET and DELETE usually have no body.

---

## 🔬 Real-world HTTP request example:

Creating a new user:

**Request:**

```http
POST https://api.example.com/signup
Headers:
Content-Type: application/json

Body:
{
  "username": "ali",
  "password": "123456"
}
```

**Response:**

```
Status Code: 201 Created
Body:
{
  "id": 123,
  "username": "ali",
  "message": "Registration successful"
}
```

# 🧩 Detailed structure of an HTTP Request

An HTTP request typically has the following structure:

```
<Method> <URL> <Version>
<Headers>

<Body>
```

## ✅ Main components of HTTP Requests:

---

## 1. 🔹 **Method:**

Specifies the action of your request:

* **GET** (retrieve data)
* **POST** (submit data to create resource)
* **PUT** (fully update resource)
* **PATCH** (partially update)
* **DELETE** (remove resource)

**Example:**

```
GET https://api.example.com/users
```

---

## 2. 🔹 **URL:**

Address of the resource:

**Example:**

```
https://api.example.com/users?page=2
```

| URL Part          | Meaning                         |
| ----------------- | ------------------------------- |
| `https://`        | Protocol (HTTPS secure or HTTP) |
| `api.example.com` | Domain/server                   |
| `/users`          | Path to the resource            |
| `?page=2`         | Query parameters                |

---

## 3. 🔹 **Headers:**

Extra information about your request or client:

| Header            | Usage                             | Example                             |
| ----------------- | --------------------------------- | ----------------------------------- |
| **Content-Type**  | Format of data (JSON, HTML, etc.) | `Content-Type: application/json`    |
| **Authorization** | Authentication (token, API Key)   | `Authorization: Bearer abc123token` |
| **Accept**        | Expected response format          | `Accept: application/json`          |

Example:

```
GET /users HTTP/1.1
Host: api.example.com
Accept: application/json
Authorization: Bearer abc123
```

---

## 4. 🔹 **Body:**

Where data is sent (for POST, PUT, PATCH methods):

**Full POST Request example:**

```http
POST /signup HTTP/1.1
Host: api.example.com
Content-Type: application/json

{
  "username": "ali",
  "password": "123456"
}
```

---

## 🌟 Full Example (PATCH):

```http
PATCH /users/123 HTTP/1.1
Host: api.example.com
Content-Type: application/json
Authorization: Bearer abc123token

{
  "email": "newemail@example.com"
}
```

Here we update only the email of user 123.

---

## 📌 Server Response:

The server replies like this:

```http
HTTP/1.1 200 OK
Content-Type: application/json

{
  "id": 123,
  "email": "newemail@example.com",
  "message": "Email updated successfully"
}
```

## 🧩 **Detailed Explanation of URL 

A URL specifies exactly where your request is sent and what you want from the server.

Consider this URL example:

```
https://api.example.com/products?page=3&limit=20
```

Components of the URL explained:

| URL Part           | Detailed explanation                                                                             |
| ------------------ | ------------------------------------------------------------------------------------------------ |
| `https://`         | **Protocol:** Specifies communication protocol (`http` or secure `https`)                        |
| `api.example.com`  | **Domain:** Main server address                                                                  |
| `/products`        | **Path:** Resource you want (like products, users, etc.)                                         |
| `?page=3&limit=20` | **Query Parameters:** Additional info for the server (`?` starts, `&` separates multiple params) |

* In this URL, we request page 3 of products, with 20 products per page.

---

### 🔖 **Other URL Examples:**

1. Retrieve specific user data:

```
https://api.example.com/users/123
```

* Fetches user data with ID 123.

2. Searching products:

```
https://api.example.com/search?keyword=laptop&sort=price
```

* Search for laptops, sorted by price.

---

## 🧩 **Detailed Explanation of Headers

Headers are extra information sent with an HTTP request to help the server understand your request better.

Headers format:

```
Header-Name: Header-Value
```

Example:

```
GET /users HTTP/1.1
Host: api.example.com
Accept: application/json
Authorization: Bearer abc123token
User-Agent: Mozilla/5.0
```

---

### 🔑 **Commonly used headers:**

| Header            | Detailed usage                          | Example                             |
| ----------------- | --------------------------------------- | ----------------------------------- |
| **Host**          | Domain/server address                   | `Host: api.example.com`             |
| **Accept**        | Expected response format (JSON, HTML)   | `Accept: application/json`          |
| **Content-Type**  | Format of data sent (POST/PUT requests) | `Content-Type: application/json`    |
| **Authorization** | Authentication (Tokens)                 | `Authorization: Bearer abc123`      |
| **User-Agent**    | Information about your browser or app   | `User-Agent: Mozilla/5.0 (Windows)` |

---

## 🚩 **Complete Example Request with URL and Headers:**

Requesting a product list from the server:

```http
GET https://api.example.com/products?page=1 HTTP/1.1
Host: api.example.com
Accept: application/json
Authorization: Bearer abc123token
User-Agent: MyMobileApp/1.0 (Android)
```

* `GET`: Request method
* `URL`: Requesting products on page 1
* `Accept`: Specifies JSON response
* `Authorization`: Authentication token
* `User-Agent`: Specifies the request originated from a mobile app
