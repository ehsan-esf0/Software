# 🌟 **Lesson 3: Data Modeling & ER Diagram (Entity-Relationship Model)**

---

### ✨ Part 1: What is Data Modeling?

* Data modeling means designing the structure of data and their relationships before building the database.
* The goal: Store data logically, with no repetition or confusion.
* Key tool: **ERD (Entity Relationship Diagram)**

---

### ✨ Part 2: Key Concepts in ER Model

1. **Entity**

   * Anything we want to store data about.
   * Examples: Student, Book, Product, Order
2. **Attribute**

   * Properties of each entity
   * Examples: Student (ID, name, age), Book (title, author)
3. **Relationship**

   * How entities are related
   * Example: Each student borrows several books

---

### ✨ Part 3: Types of Relationships (Cardinality)

* **One-to-One (1:1):** Each manager has one office, each office has one manager.
* **One-to-Many (1\:N):** Each teacher has many students, each student has one advisor.
* **Many-to-Many (N\:M):** Each student takes several courses, each course has many students.

---

### ✨ Part 4: Example Simple ER Diagram

Imagine a university where you want to store only students and courses.

* Entities: Student, Course
* Student attributes: ID, name, age
* Course attributes: course ID, course name
* Relationship: Each student can take several courses; each course can have several students (many-to-many)

---

### ✨ Part 5: Simple Model in Code

#### 🐍 Python

```python
# Define Student and Course classes
class Student:
    def __init__(self, id, name, age):
        self.id = id
        self.name = name
        self.age = age
        self.courses = []  # List of the student's courses

class Course:
    def __init__(self, id, title):
        self.id = id
        self.title = title
        self.students = []  # List of students for each course

# Create instances
student1 = Student(1, "Ali", 21)
course1 = Course(101, "Database")

# Set relationship
student1.courses.append(course1)
course1.students.append(student1)

print(f"Student: {student1.name}, Courses: {[c.title for c in student1.courses]}")
```

**Output:**
Student: Ali, Courses: \['Database']

---

#### 💻 C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Course; // Forward declaration

struct Student {
    int id;
    string name;
    int age;
    vector<Course*> courses;
};

struct Course {
    int id;
    string title;
    vector<Student*> students;
};

int main() {
    Student ali = {1, "Ali", 21};
    Course db = {101, "Database"};

    ali.courses.push_back(&db);
    db.students.push_back(&ali);

    cout << "Student: " << ali.name << ", Courses: " << ali.courses[0]->title << endl;
    return 0;
}
```

**Output:**
Student: Ali, Courses: Database
