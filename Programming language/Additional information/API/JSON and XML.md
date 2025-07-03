# 📚 Lesson 5: Understanding JSON and XML

When working with APIs, data is usually exchanged in two common formats:

* **JSON (JavaScript Object Notation)**
* **XML**

Let's explore each deeply:

---

## 🔹 What is JSON?

**JSON (JavaScript Object Notation)** is a lightweight, simple, and fast standard data exchange format.

### 📌 JSON Features:

* Easy to read and write by humans.
* Lightweight and fast for data transfer.
* Directly usable in JavaScript and languages like Python, Java, PHP.

### ✅ JSON Structure:

JSON includes:

* Object `{...}`
* Array `[...]`
* String, Number, Boolean, null

### 📝 JSON Example:

```json
{
  "name": "Ali",
  "age": 25,
  "isStudent": true,
  "skills": ["Programming", "Design"],
  "address": {
    "city": "Tehran",
    "street": "Azadi street"
  }
}
```

**Explanation:**

* `name` → String
* `age` → Number
* `isStudent` → Boolean
* `skills` → Array
* `address` → Nested Object

---

## 🔹 What is XML?

**XML (eXtensible Markup Language)** is a structured markup language for transferring data. It was very common before JSON, now less popular.

### 📌 XML Features:

* Highly structured
* Human-readable, but heavier than JSON
* Suitable for complex data transfer

### ✅ XML Structure:

XML uses tags (`<tag>`):

```xml
<user>
  <name>Ali</name>
  <age>25</age>
  <isStudent>true</isStudent>
  <skills>
    <skill>Programming</skill>
    <skill>Design</skill>
  </skills>
  <address>
    <city>Tehran</city>
    <street>Azadi street</street>
  </address>
</user>
```

**Explanation:**

* Data enclosed within opening and closing tags.
* Can handle nested data structures.

---

## 🧩 JSON vs XML comparison:

| Feature        | JSON            | XML          |
| -------------- | --------------- | ------------ |
| Readability    | Easier, simpler | More complex |
| Data Size      | Lightweight     | Heavier      |
| Transfer Speed | Faster          | Slower       |
| Usage on Web   | Popular         | Less popular |

---

## 🔬 Working with JSON in JavaScript (Detailed example):

Convert JSON string to JavaScript object:

```js
let jsonText = '{"name": "Ali", "age": 25}';
let obj = JSON.parse(jsonText);
console.log(obj.name); // Ali
```

Convert JavaScript object to JSON string:

```js
let obj = {name: "Ali", age: 25};
let jsonText = JSON.stringify(obj);
console.log(jsonText); // {"name":"Ali","age":25}
```

---

## 🧪 Your Practical Exercise:

Take the JSON below and examine it with [JSON Parser](https://jsonformatter.org/json-parser). See what's inside:

```json
{
  "product": {
    "id": 101,
    "name": "Laptop",
    "price": 2500,
    "features": ["RAM 16GB", "SSD 512GB"]
  },
  "available": true
}
```
