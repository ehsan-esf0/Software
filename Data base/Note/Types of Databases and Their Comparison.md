# 🌈 **Lesson 2: Types of Databases and Their Comparison**

---

### ✨ Part 1: Types of Databases

#### 1. Relational Database

* Data is stored in tables (rows and columns).
* Tables can be related to each other (primary and foreign keys).
* Uses SQL query language.
* Examples: MySQL, PostgreSQL, SQL Server, Oracle

#### 2. NoSQL Database

* Data is stored in non-tabular formats.
* Types:

  * Key-Value: Redis
  * Document: MongoDB
  * Graph: Neo4j
  * Columnar: Cassandra
* Great for large volumes of data, high speed, and unstructured data

#### 3. File-based Database

* Data is stored as plain files (e.g., CSV or XML).
* Simple structure, no advanced features
* Good for very simple and small projects

---

### ✨ Part 2: General Comparison Table

| Feature        | Relational           | NoSQL                   | File-based             |
| -------------- | -------------------- | ----------------------- | ---------------------- |
| Data Structure | Table                | Various (Doc, Key, ...) | Plain file (Text, CSV) |
| Query Language | SQL                  | Depends on DB type      | None                   |
| Speed          | Good                 | Very high (sometimes)   | Low                    |
| Flexibility    | Medium               | Very high               | Low                    |
| Complexity     | Medium               | Medium to high          | Low                    |
| Use Case       | Traditional projects | Big data, flexible      | Simple/small projects  |

---

### ✨ Part 3: When to Choose Which?

* For structured data with complex relationships: **Relational**
* For big data with variable/unstructured format: **NoSQL**
* For very simple and lightweight projects: **File-based**

---

### ✨ Part 4: Real-World Examples

* **Relational:** Registering orders and users in an online store
* **NoSQL (Document):** Storing messages in social media apps
* **NoSQL (Graph):** Analyzing user relations in social networks like LinkedIn
* **File-based:** Storing speed test results in a text file

---

### ✨ Part 5: Code Example (Saving Data)

#### 🐍 Python: Saving Data in Different Ways

```python
# Saving data as a text file
with open('data.txt', 'w', encoding='utf-8') as f:
    f.write("Name: Ali\nAge: 22\nCity: Tehran\n")

# Saving data as a dictionary (like NoSQL Document)
data = {"name": "Ali", "age": 22, "city": "Tehran"}

# Saving data in a table (like Relational)
import sqlite3
conn = sqlite3.connect('mydb.db')
c = conn.cursor()
c.execute("CREATE TABLE IF NOT EXISTS users (name TEXT, age INTEGER, city TEXT)")
c.execute("INSERT INTO users VALUES (?, ?, ?)", ("Ali", 22, "Tehran"))
conn.commit()
conn.close()
```

---

#### 💻 C++: Saving Data to a Text File

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("data.txt");
    file << "Name: Ali\nAge: 22\nCity: Tehran\n";
    file.close();
    cout << "Data saved." << endl;
    return 0;
}
```