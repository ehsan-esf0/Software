# 🚀 Lesson 6: Creating Your First Simple API 

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
Certainly! Here’s a detailed and complete explanation, fully in **English**, of all possible scenarios using the **Flask** (server-side) and **requests** (client-side) libraries for handling API interactions.

---

# 🚩 Complete API Interaction using Flask & requests (Python)

In any API-based Python application, there are typically two distinct roles:

* **Server (Flask):** Receives, processes, and responds to HTTP requests.
* **Client (requests):** Sends HTTP requests to external APIs and handles responses.

Let’s explore each HTTP method thoroughly, including detailed code examples.

---

# 🟢 **1. Server-side (Flask)**

The Flask framework handles incoming HTTP requests and sends appropriate responses back to the client.

---

## ✅ **GET (Fetch data)**

Retrieves data from the server:

```python
from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/users', methods=['GET'])
def get_users():
    users = [
        {"id": 1, "name": "Ali"},
        {"id": 2, "name": "Sara"}
    ]
    return jsonify(users)

if __name__ == '__main__':
    app.run(debug=True)
```

**Explanation:**

* Receives a GET request at `/users`.
* Returns a JSON list of users.

---

## ✅ **POST (Create new data)**

Creates new data/resources on the server:

```python
from flask import Flask, jsonify, request

app = Flask(__name__)

@app.route('/users', methods=['POST'])
def create_user():
    data = request.json  # Gets JSON data sent by client
    new_user = {"id": 3, "name": data["name"]}
    return jsonify(new_user), 201  # 201 indicates successful creation

if __name__ == '__main__':
    app.run(debug=True)
```

**Explanation:**

* Receives JSON data via POST request.
* Creates and returns the new resource.

---

## ✅ **PUT (Fully update data)**

Completely updates an existing resource:

```python
@app.route('/users/<int:user_id>', methods=['PUT'])
def update_user(user_id):
    data = request.json
    updated_user = {"id": user_id, "name": data["name"]}
    return jsonify(updated_user), 200
```

**Explanation:**

* Updates user with the provided `user_id`.
* Requires sending all fields for complete update.

---

## ✅ **PATCH (Partially update data)**

Updates only specified fields of an existing resource:

```python
@app.route('/users/<int:user_id>', methods=['PATCH'])
def partial_update_user(user_id):
    data = request.json
    # Mock partial update logic
    updated_user = {"id": user_id, **data}
    return jsonify(updated_user), 200
```

**Explanation:**

* Updates specific fields, preserving others.

---

## ✅ **DELETE (Remove data)**

Deletes a resource:

```python
@app.route('/users/<int:user_id>', methods=['DELETE'])
def delete_user(user_id):
    # Mock delete logic
    return jsonify({"message": f"User {user_id} deleted successfully."}), 200
```

**Explanation:**

* Removes resource identified by `user_id`.

---

# 🔵 **2. Client-side (requests)**

The `requests` library is used to interact with external APIs by sending HTTP requests and handling responses.

---

## ✅ **GET (Fetch data)**

Fetch data from an API endpoint:

```python
import requests

response = requests.get("https://example.com/api/users")

if response.status_code == 200:
    users = response.json()
    print(users)
else:
    print(f"Error: {response.status_code}")
```

**Explanation:**

* Sends a GET request and processes JSON response.

---

## ✅ **POST (Create new data)**

Send new data to the server:

```python
import requests

new_user = {"name": "Ali"}

response = requests.post("https://example.com/api/users", json=new_user)

if response.status_code == 201:
    created_user = response.json()
    print("User created:", created_user)
else:
    print(f"Error: {response.status_code}")
```

**Explanation:**

* Creates a resource by sending JSON data to the server.

---

## ✅ **PUT (Fully update data)**

Completely update existing data:

```python
import requests

updated_user = {"name": "Ali Mohammadi"}

response = requests.put("https://example.com/api/users/1", json=updated_user)

if response.status_code == 200:
    user = response.json()
    print("User updated:", user)
else:
    print(f"Error: {response.status_code}")
```

**Explanation:**

* Sends complete data to replace the existing resource.

---

## ✅ **PATCH (Partially update data)**

Partially update existing data:

```python
import requests

partial_update = {"name": "Ali Reza Mohammadi"}

response = requests.patch("https://example.com/api/users/1", json=partial_update)

if response.status_code == 200:
    user = response.json()
    print("User partially updated:", user)
else:
    print(f"Error: {response.status_code}")
```

**Explanation:**

* Updates only provided fields of the resource.

---

## ✅ **DELETE (Remove data)**

Delete existing data:

```python
import requests

response = requests.delete("https://example.com/api/users/1")

if response.status_code == 200:
    print("User deleted successfully.")
else:
    print(f"Error: {response.status_code}")
```

**Explanation:**

* Sends a DELETE request to remove the resource.

---

# ⚙️ **Important Parameters in `requests` library**

* `json=data`: Sends data in JSON format.
* `response.status_code`: Provides HTTP status of the response (200 for success, 201 for created).
* `response.json()`: Converts JSON response to Python object.

---

# ⚙️ **Important Functions in Flask**

* `@app.route('/path', methods=['GET', 'POST', ...])`: Defines endpoint path and allowed HTTP methods.
* `request.json`: Retrieves JSON data sent by the client.
* `jsonify(...)`: Converts Python data structures into JSON responses.
* `return jsonify(...), status_code`: Returns JSON responses along with HTTP status code.

---

# 🔄 **Combining Server & Client (Flask + requests)**

A common scenario is to have your Flask server act as a client to another API.

Example:

```python
from flask import Flask, jsonify
import requests

app = Flask(__name__)

@app.route('/external-posts', methods=['GET'])
def get_external_posts():
    external_response = requests.get('https://jsonplaceholder.typicode.com/posts')
    if external_response.status_code == 200:
        posts = external_response.json()
        return jsonify(posts)
    else:
        return jsonify({"error": "Unable to fetch data from external API"}), 500

if __name__ == '__main__':
    app.run(debug=True)
```

**Explanation:**

* Flask acts as both server (handling incoming request) and client (sending outgoing request).
* Fetches data from external API and forwards it back to client.

---

## 🚩 **Summary Table**

| Method | Flask (Server-side)                            | requests (Client-side)           |
| ------ | ---------------------------------------------- | -------------------------------- |
| GET    | `@app.route('/path', methods=['GET'])`         | `requests.get(url)`              |
| POST   | `@app.route('/path', methods=['POST'])`        | `requests.post(url, json=data)`  |
| PUT    | `@app.route('/path/<id>', methods=['PUT'])`    | `requests.put(url, json=data)`   |
| PATCH  | `@app.route('/path/<id>', methods=['PATCH'])`  | `requests.patch(url, json=data)` |
| DELETE | `@app.route('/path/<id>', methods=['DELETE'])` | `requests.delete(url)`           |

---