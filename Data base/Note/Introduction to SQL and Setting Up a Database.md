# 🌟 **Lesson 4: Introduction to SQL and Setting Up a Database**

---

### ✨ Part 1: What is SQL?

* **SQL** stands for **Structured Query Language**; a standard language for creating, managing, and interacting with relational databases.
* With SQL you can **INSERT**, **SELECT**, **UPDATE**, and **DELETE** data.
* Almost all relational databases (MySQL, PostgreSQL, SQL Server, Oracle, etc.) use SQL.

---

### ✨ Part 2: Installing & Setting Up a Database (Example: MySQL and SQLite)

#### **MySQL**

* One of the world’s most popular free and powerful databases.
* Easy to install on Windows, Mac, or Linux (download from the official website or install via command line).

#### **SQLite**

* A lightweight database that requires no server installation.
* Great for small projects or practice (built-in with Python).

---

### ✨ Part 3: Connecting to a Database and Running Your First SQL Command

#### 🐍 Python Example (using SQLite):

```python
import sqlite3

# Create/connect to a database file
conn = sqlite3.connect('mydb.db')
c = conn.cursor()

# Create a users table
c.execute('''
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY,
    name TEXT,
    age INTEGER
)
''')

# Add a user
c.execute("INSERT INTO users (name, age) VALUES (?, ?)", ("Ali", 22))

# Show all users
c.execute("SELECT * FROM users")
users = c.fetchall()
print(users)  # [(1, 'Ali', 22)]

conn.commit()
conn.close()
```

---

#### 💻 C++ Example (creating a SQL script file):

```cpp
#include <fstream>
using namespace std;

int main() {
    ofstream sqlfile("commands.sql");
    sqlfile << "CREATE TABLE users (id INT PRIMARY KEY, name VARCHAR(100), age INT);\n";
    sqlfile << "INSERT INTO users (id, name, age) VALUES (1, 'Ali', 22);\n";
    sqlfile << "SELECT * FROM users;\n";
    sqlfile.close();
    return 0;
}
```

*(This code generates a SQL script file you can run in MySQL or similar tools.)*

---

### ✨ Part 4: Basic SQL Statement Structure

* **Create Table:**

  ```sql
  CREATE TABLE users (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    age INT
  );
  ```
* **Insert Data:**

  ```sql
  INSERT INTO users (id, name, age) VALUES (1, 'Ali', 22);
  ```
* **Show Data:**

  ```sql
  SELECT * FROM users;
  ```
* **Update Data:**

  ```sql
  UPDATE users SET age = 23 WHERE id = 1;
  ```
* **Delete Data:**

  ```sql
  DELETE FROM users WHERE id = 1;
  ```

---
