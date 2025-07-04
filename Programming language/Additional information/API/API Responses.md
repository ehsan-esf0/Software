# ✅ **Lesson 8 Recap: Designing API Responses**

### 🔹 A good API response should:

* Be in **JSON** format
* Include clear and consistent fields like:

  * `success` (boolean)
  * `data` (actual result)
  * `message` (optional readable message)
  * `errors` (when needed)
* Use correct **HTTP status codes** (e.g., `200`, `404`, `500`)
* Follow a **uniform structure** for all endpoints

---

### 🧪 Mini Task (from Lesson 8):

> User tries to get product with ID `999`, but it doesn’t exist.
> ✅ Proper response:

**Status code:**

```http
404 Not Found
```

**JSON body:**

```json
{
  "success": false,
  "message": "Product not found",
  "errors": {
    "code": 404,
    "details": "No product exists with ID 999"
  }
}
```

---

# 📘 **Lesson 9: Using Query Parameters and Filtering in APIs**

---

## 🔸 Part 1: What are Query Parameters?

**Query parameters** are values sent in the URL to filter, sort, or customize the request.

They come after a `?` in the URL and are written like this:

```
?key=value
```

You can combine multiple parameters with `&`.

---

### 🎯 Example:

```http
GET /api/products?category=books&sort=price&limit=10
```

This request means:

* Get products **only in the "books" category**
* **Sort by price**
* **Limit to 10 results**

---

## 🔸 Part 2: Common Query Parameters

| Parameter   | Purpose                                     |
| ----------- | ------------------------------------------- |
| `limit`     | Limit number of results                     |
| `page`      | For pagination                              |
| `sort`      | Sort results (e.g., `sort=price`)           |
| `order`     | Ascending or descending (e.g., `order=asc`) |
| `search`    | Keyword search                              |
| `filter_by` | Filter by specific field                    |

---

## 🔸 Part 3: How to Handle Them in Backend (Python / Flask example)

```python
@app.route('/api/products', methods=['GET'])
def get_products():
    category = request.args.get('category')
    sort = request.args.get('sort')
    limit = request.args.get('limit', default=20, type=int)

    # Sample logic
    return jsonify({
        "success": True,
        "filters": {
            "category": category,
            "sort": sort,
            "limit": limit
        },
        "data": []  # here you would normally return filtered products
    })
```

---

## 🔸 Part 4: Clean URLs – Best Practices

| Rule                                          | Example                                |
| --------------------------------------------- | -------------------------------------- |
| Use plural nouns                              | `/products`, not `/productList`        |
| Use query parameters only for optional values | Don't encode resource type in the path |
| Don't make long unreadable URLs               | Keep them meaningful and readable      |

---

## 🧪 Mini Exercise:

Design a query for the following case:

> I want to get the **first 5 laptops**, **sorted by price (ascending)**, and only those that are **in stock**.

✅ What should the request URL look like?

You can try writing it and I’ll check it for you.

---

## ✅ Summary:

* Query parameters allow clients to **filter, sort, and customize** results.
* Keep your URLs **clean** and **RESTful**.
* Your backend should **read `request.args`** and apply logic accordingly.
