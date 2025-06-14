# 🔹 `const_cast` in C++

## ✅ Purpose:
Used to **add or remove const/volatile qualifiers** from a variable.

## ⚠️ Safety:
Only safe if the original object **was not actually const**.

## 🧪 Example:
```cpp
void legacyPrint(char* str);

void safePrint(const char* str) {
    legacyPrint(const_cast<char*>(str));  // Removing const to call legacy function
}
```

## 🔍 Notes:
- Never use it to modify a truly const object. Leads to **undefined behavior**.