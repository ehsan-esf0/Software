# 🌟 Lesson 6: Basic Data Operations (CRUD)

---

### ✨ Section 1: General CRUD Tips

* **CRUD** = Create, Read, Update, Delete (the 4 main operations in databases)
* Almost every DBMS implements these 4 functions.
* The correct order of operations matters in real projects.
* Operations are performed on **rows (records)**, not the whole table (unless you specify so).

---

### ✨ Section 2: CREATE/INSERT Notes & Commands

1. **Insert a single record:**

   ```sql
   INSERT INTO users (name, age) VALUES ('Ali', 22);
   ```

   * For auto-increment fields, you don’t need to enter their value manually.
2. **Insert multiple records in one command:**

   ```sql
   INSERT INTO users (name, age) VALUES 
      ('Ali', 22),
      ('Maryam', 30),
      ('Mohammad', 25);
   ```
3. **Insert only specific columns:**
   List only the columns you want to insert; other columns must be NULL or have a default value.
4. **Note:** If a column is **NOT NULL**, you must provide a value.
5. **Using DEFAULT:**

   ```sql
   CREATE TABLE test (
     id INT PRIMARY KEY AUTO_INCREMENT,
     name VARCHAR(100) DEFAULT 'Unknown'
   );
   ```

---

### ✨ Section 3: READ/SELECT Notes & Commands

1. **Read all data:**

   ```sql
   SELECT * FROM users;
   ```
2. **Read specific columns:**

   ```sql
   SELECT name, age FROM users;
   ```
3. **Conditional queries (WHERE):**

   ```sql
   SELECT * FROM users WHERE age > 20;
   ```

   * WHERE operators: `=`, `!=`, `>`, `<`, `>=`, `<=`, `IN`, `BETWEEN`, `LIKE`, `IS NULL`, etc.
   * LIKE example (pattern search):

     ```sql
     SELECT * FROM users WHERE name LIKE 'A%'; -- names starting with A
     ```
   * IN example:

     ```sql
     SELECT * FROM users WHERE age IN (22, 25, 30);
     ```
4. **Ordering results (ORDER BY):**

   ```sql
   SELECT * FROM users ORDER BY age DESC;
   ```

   * `DESC` = descending; `ASC` = ascending (default)
5. **Limiting number of rows (LIMIT):**

   ```sql
   SELECT * FROM users LIMIT 5;
   ```
6. **Select distinct values (DISTINCT):**

   ```sql
   SELECT DISTINCT age FROM users;
   ```
7. **Combining conditions (AND/OR/NOT):**

   ```sql
   SELECT * FROM users WHERE age > 20 AND name = 'Ali';
   ```
8. **Renaming output columns (AS):**

   ```sql
   SELECT name AS full_name FROM users;
   ```
9. **Aggregate functions (COUNT, AVG, MIN, MAX, SUM):**

   ```sql
   SELECT COUNT(*) FROM users;
   SELECT AVG(age) FROM users;
   ```

---

### ✨ Section 4: UPDATE Notes & Commands

1. **Update a single column:**

   ```sql
   UPDATE users SET age = 23 WHERE name = 'Ali';
   ```
2. **Update multiple columns at once:**

   ```sql
   UPDATE users SET age = 25, name = 'Mohammad' WHERE id = 3;
   ```
3. **Update all rows (danger!):**

   ```sql
   UPDATE users SET age = 40;
   ```

   **Warning:** Without WHERE, all records are changed!
4. **Use functions in UPDATE:**

   ```sql
   UPDATE users SET age = age + 1 WHERE age < 20;
   ```

---

### ✨ Section 5: DELETE Notes & Commands

1. **Delete a specific record:**

   ```sql
   DELETE FROM users WHERE name = 'Ali';
   ```
2. **Delete with multiple conditions:**

   ```sql
   DELETE FROM users WHERE age > 30 AND name LIKE 'M%';
   ```
3. **Delete all records (super dangerous!):**

   ```sql
   DELETE FROM users;
   ```

   Or (even faster, but irreversible):

   ```sql
   TRUNCATE TABLE users;
   ```

   **Warning:** All records are gone!
4. **Deleting duplicates:**
   Usually done with subqueries and IDs.

---

### ✨ Section 6: Security & Pro Tips

* **Always run a SELECT with your WHERE before a DELETE or UPDATE to check what will be affected!**
* Use **PRIMARY KEY** for unique data identification.
* For sensitive data, use **transactions** so you can ROLLBACK if something goes wrong.
* **Very Important:** In programming, always use parameterized queries to prevent SQL Injection.

---

### ✨ Section 7: More Useful CRUD Commands

* **INSERT OR IGNORE / REPLACE:** To avoid errors on duplicate insert (in SQLite)

  ```sql
  INSERT OR IGNORE INTO users (id, name) VALUES (1, 'Ali');
  ```
* **ON DUPLICATE KEY UPDATE** (MySQL)

  ```sql
  INSERT INTO users (id, name) VALUES (1, 'Ali') 
  ON DUPLICATE KEY UPDATE name='Ali New';
  ```
* **RETURNING:** To show the inserted/updated record (PostgreSQL)

  ```sql
  INSERT INTO users (name) VALUES ('Ali') RETURNING id;
  ```

---

### ✨ Section 8: Key Points & Common Mistakes

* Forgetting WHERE in UPDATE or DELETE = changes or deletes ALL records!
* Wrong column names in SELECT = error.
* In INSERT, column order must match values order.
* Text data must be in single quotes (`'`).
* You can’t use = with NULL, use `IS NULL` instead.

---

### ✨ Section 9: Full Example Using All Commands

```sql
-- Create table
CREATE TABLE users (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  name VARCHAR(100),
  age INTEGER
);

-- Insert data
INSERT INTO users (name, age) VALUES ('Ali', 22), ('Maryam', 30), ('Sara', 28);

-- Read
SELECT * FROM users WHERE age > 25 ORDER BY age DESC;

-- Update
UPDATE users SET age = 29 WHERE name = 'Sara';

-- Delete
DELETE FROM users WHERE age < 25;
```
