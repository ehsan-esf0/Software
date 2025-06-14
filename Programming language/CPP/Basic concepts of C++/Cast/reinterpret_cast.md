# 🔹 `reinterpret_cast` in C++

## ⚠️ Purpose:
Performs **bit-level reinterpretation** of types.

## 🚨 Warning:
This is a **very low-level** operation. Can break portability and lead to undefined behavior.

## 🧪 Example:
```cpp
int a = 65;
char* c = reinterpret_cast<char*>(&a);
std::cout << *c;  // Might print 'A'

void func(int) {}
void (*fp)() = reinterpret_cast<void (*)()>(func);  // Function pointer cast
```

## 🔍 Notes:
- Use only when absolutely necessary.
- Never used for general-purpose type conversions.