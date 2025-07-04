# 📘 **Lesson 7: Designing Proper API Endpoints**

---

## 🔸 Part 1: What is an Endpoint?

### ✅ **Definition:**

An **endpoint** is a specific URL path in your API that a client (like a browser, mobile app, or JavaScript code) can send requests to.

### 🎯 Simple Example:

If your API is hosted at:

```
https://myapi.com
```

And you want to fetch products:

```
GET https://myapi.com/api/products
```

* `https://myapi.com` → base domain
* `/api/products` → **endpoint** (specific route where the API handles requests)

---

## 🔸 Part 2: Best Practices for Designing Endpoints

### ✅ **General rules:**

#### 1. **Use plural nouns**

* Good: `/products`
* Bad: `/product`

#### 2. **Don't use verbs in the path**

* ❌ `/getProducts`
* ✅ `/products`
  The **HTTP method** (GET, POST, etc.) already describes the action.

#### 3. **Use hierarchical structure for relationships**

Example: all orders for user with ID 42:

```
GET /api/users/42/orders
```

---

## 🔸 Part 3: Standard RESTful Endpoint Patterns

| HTTP Method | Endpoint           | Action                 |
| ----------- | ------------------ | ---------------------- |
| GET         | `/api/products`    | Get all products       |
| GET         | `/api/products/12` | Get a specific product |
| POST        | `/api/products`    | Create a new product   |
| PUT         | `/api/products/12` | Update a product       |
| DELETE      | `/api/products/12` | Delete a product       |

---

## 🔸 Part 4: Pro Tips for Better API Design

| Tip                       | Description                                             |
| ------------------------- | ------------------------------------------------------- |
| Use versioning            | `/api/v1/products`                                      |
| Return & accept JSON      | Standardize data format                                 |
| Use clear error messages  | Proper status codes and messages (e.g. `404 Not Found`) |
| Keep paths short & simple | Avoid long or vague names                               |
| Add filtering and sorting | Example: `/api/products?category=books&sort=price`      |

---

## 🧪 Mini Exercise

Let’s say you're building an API for an online store. Design endpoints for:

1. Getting all orders for user with ID 5
2. Creating a new product
3. Deleting a category with ID 9

Feel free to send your answers and I’ll check them for you 😊

---

## ✅ Summary

* An **endpoint** is a URL that your server listens to.
* Good endpoint design follows RESTful patterns.
* Use plural nouns, HTTP methods, and clear, consistent naming.
