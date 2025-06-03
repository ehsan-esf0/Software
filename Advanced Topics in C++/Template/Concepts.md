# Concepts (C++20)

A modern and readable alternative to SFINAE.

```cpp
#include <concepts>
#include <iostream>

template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T add(T a, T b) {
    return a + b;
}
```

