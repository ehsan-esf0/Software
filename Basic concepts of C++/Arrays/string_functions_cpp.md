# 📘 Most Commonly Used string Functions in C++

This table summarizes the most useful methods of the `std::string` class in C++, with descriptions and usage examples.

| Function              | Description                                      | Example                                     |
|-----------------------|--------------------------------------------------|---------------------------------------------|
| `size()` / `length()` | Returns the length of the string                 | `s.size()` or `s.length()`                  |
| `empty()`             | Checks if the string is empty                    | `if (s.empty())`                            |
| `clear()`             | Clears the entire string                         | `s.clear()`                                 |
| `at(pos)`             | Access character at position with bounds check   | `char c = s.at(2);`                         |
| `operator[]`          | Access character (no bounds check)               | `char c = s[1];`                            |
| `append(str)`         | Appends a string                                 | `s.append("world");`                        |
| `+=`                  | Concatenates a string                            | `s += "hello";`                             |
| `insert(pos, str)`    | Inserts a string at position                     | `s.insert(1, "abc");`                       |
| `erase(pos, len)`     | Erases `len` characters from `pos`              | `s.erase(3, 2);`                            |
| `replace(pos, len, str)` | Replaces part of string with another         | `s.replace(0, 3, "hi");`                    |
| `substr(pos, len)`    | Returns a substring                             | `s.substr(2, 4);`                           |
| `find(str)`           | Finds first occurrence                          | `s.find("abc");`                            |
| `rfind(str)`          | Finds last occurrence                           | `s.rfind("abc");`                           |
| `find_first_of(set)`  | Finds first occurrence of any char in set       | `s.find_first_of("aeiou");`                |
| `find_last_of(set)`   | Finds last occurrence of any char in set        | `s.find_last_of("aeiou");`                 |
| `compare(str)`        | Compares with another string                    | `s.compare("abc") == 0`                     |
| `c_str()`             | Gets C-style string (`const char*`)             | `const char* p = s.c_str();`                |
| `begin()` / `end()`   | Returns iterators to begin/end                  | `for (auto it = s.begin(); it != s.end(); ++it)` |
| `push_back(ch)`       | Appends a single character                      | `s.push_back('!');`                         |
| `pop_back()`          | Removes last character                          | `s.pop_back();`                             |
| `front()`             | Returns the first character                     | `char c = s.front();`                       |
| `back()`              | Returns the last character                      | `char c = s.back();`                        |
| `resize(n)`           | Resizes the string                              | `s.resize(10);`                             |
| `shrink_to_fit()`     | Frees extra memory                              | `s.shrink_to_fit();`                        |
| `reserve(n)`          | Reserves capacity for at least `n` characters   | `s.reserve(100);`                           |
| `swap(str)`           | Swaps contents with another string              | `s.swap(s2);`                               |
