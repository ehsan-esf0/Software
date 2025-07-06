# 🌟 **Lesson 5: Creating Tables & Data Types in Database**

---

### ✨ Part 1: Creating a Table in SQL

* **Table** is a main part of a database that stores data in rows and columns.
* Each table has fields (columns) with a defined data type, and records (rows) of information.

---

#### **General Structure for Creating a Table**

```sql
CREATE TABLE table_name (
  column1 datatype [constraint],
  column2 datatype [constraint],
  ...
);
```

---

#### **Simple Example: Users Table**

```sql
CREATE TABLE users (
  id INTEGER PRIMARY KEY,
  name VARCHAR(100),
  age INTEGER
);
```

* **id:** Integer, primary key
* **name:** String, up to 100 characters
* **age:** Integer

---

### ✨ Part 2: Common Data Types in SQL

| Data Type     | Description                          | Example             |
| ------------- | ------------------------------------ | ------------------- |
| INTEGER / INT | Integer (no decimals)                | 15                  |
| FLOAT / REAL  | Floating-point number                | 12.5                |
| CHAR(n)       | Fixed-length string                  | 'A'                 |
| VARCHAR(n)    | Variable-length string (max n chars) | 'Ali'               |
| TEXT          | Long text                            | 'Some long text'    |
| DATE          | Date                                 | 2024-06-21          |
| TIME          | Time                                 | 14:30:00            |
| DATETIME      | Date and time                        | 2024-06-21 14:30:00 |

---

### ✨ Part 3: Creating a Table with Different Data Types

```sql
CREATE TABLE books (
  id INTEGER PRIMARY KEY,
  title VARCHAR(200),
  author VARCHAR(100),
  published_date DATE,
  price REAL
);
```

* **id:** Primary key, integer
* **title:** Book title, up to 200 chars
* **author:** Author name
* **published\_date:** Date of publication
* **price:** Book price, decimal

---

### ✨ Part 4: Coding Example with Python & C++

#### 🐍 Python: Create Table & Insert Data

```python
import sqlite3

conn = sqlite3.connect('library.db')
c = conn.cursor()

# Create table
c.execute('''
CREATE TABLE IF NOT EXISTS books (
    id INTEGER PRIMARY KEY,
    title TEXT,
    author TEXT,
    published_date DATE,
    price REAL
)
''')

# Insert data
c.execute("INSERT INTO books (title, author, published_date, price) VALUES (?, ?, ?, ?)",
          ("Geek's Diary", "Ali Rezaei", "2024-06-21", 120.5))

# Show data
c.execute("SELECT * FROM books")
for row in c.fetchall():
    print(row)

conn.commit()
conn.close()
```

---

#### 💻 C++: Create a SQL File for Table Creation

```cpp
#include <fstream>
using namespace std;

int main() {
    ofstream sqlfile("create_books_table.sql");
    sqlfile << "CREATE TABLE books (\n";
    sqlfile << "  id INT PRIMARY KEY,\n";
    sqlfile << "  title VARCHAR(200),\n";
    sqlfile << "  author VARCHAR(100),\n";
    sqlfile << "  published_date DATE,\n";
    sqlfile << "  price REAL\n";
    sqlfile << ");\n";
    sqlfile.close();
    return 0;
}
```

*(This code generates an SQL file to run in your DBMS tool.)*

---

### ✨ Part 5: Exercise (For You!)

1. Create a table for students with columns: `id` (primary key), `name`, `major`, `birthdate`, and `gpa` (as a decimal).
2. Add three students to the table (SQL command).
3. Display all students using Python or SQL.

---
