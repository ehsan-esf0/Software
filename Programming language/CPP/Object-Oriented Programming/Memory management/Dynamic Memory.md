# 🚗 Dynamic Memory

---

## 🔹 1. What is Dynamic Memory?

Dynamic memory refers to memory that is allocated **at runtime**, using the heap.
This allows for flexible memory usage when the size or number of objects is not known at compile time.

```cpp
int* ptr = new int; // allocates memory for one integer
*ptr = 10;

delete ptr;         // frees the memory
```

---

## 🔹 2. Using `new` and `delete`

### ✅ Allocating a single value:

```cpp
int* num = new int;
*num = 42;

delete num;
```

### ✅ Allocating a dynamic array:

```cpp
int* arr = new int[5];

for (int i = 0; i < 5; ++i)
    arr[i] = i * 2;

delete[] arr;
```

> 🔸 **Use `delete[]` for arrays!** Never mix `new` with `delete[]`.

---

## 🔹 3. Reusing a Pointer After Deletion

Yes, you can reuse a pointer after `delete` by assigning new memory:

```cpp
int* ptr = new int;
*ptr = 5;
delete ptr;

ptr = new int;
*ptr = 100;

delete ptr;
```

⚠️ **Danger!** Never use a pointer after `delete` without reinitializing it.

```cpp
int* p = new int;
delete p;

// ❌ Undefined behavior:
std::cout << *p; 
```

✅ Best Practice:

```cpp
delete p;
p = nullptr;
```

---

## 🔹 4. Dynamic Memory in Classes (Object-Oriented Style)

### 👇 Dynamic memory inside a class:

```cpp
class MyArray {
private:
    int* data;
    int size;
public:
    MyArray(int s) {
        size = s;
        data = new int[size];
    }

    ~MyArray() {
        delete[] data;
    }

    void set(int i, int value) { data[i] = value; }
    int get(int i) const { return data[i]; }
};
```

---

## 🔹 5. Dynamic Array of Objects

```cpp
class Person {
public:
    void greet() { std::cout << "Hello!\n"; }
};

Person* group = new Person[3];
group[0].greet();
delete[] group;
```

---

## 🔹 6. Rule of Three

If your class:

* allocates dynamic memory,
* defines a destructor,

...you should also define:

* copy constructor
* copy assignment operator

```cpp
class MyClass {
    int* data;
public:
    MyClass(const MyClass& other) {
        data = new int;
        *data = *(other.data);  // deep copy
    }

    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int;
            *data = *(other.data);
        }
        return *this;
    }

    ~MyClass() { delete data; }
};
```

---

## 🔹 7. Smart Alternatives (Modern C++)

### 🧠 `std::vector`

```cpp
#include <vector>
std::vector<int> vec(10); // automatic cleanup, no delete needed!
```

### 🧠 `std::unique_ptr`

```cpp
#include <memory>
std::unique_ptr<int[]> arr(new int[5]); // cleans itself up
```

---

## 🎯 Summary Table

| Task                    | Old C++       | Modern C++                    |
| ----------------------- | ------------- | ----------------------------- |
| Allocate memory         | `new`         | `std::make_unique`            |
| Deallocate memory       | `delete`      | automatic                     |
| Dynamic array           | `new[]`       | `std::vector`                 |
| Manual memory control   | error-prone   | safer alternatives            |
| Class memory management | Rule of Three | Rule of Five / Smart Pointers |
