# SFINAE (Substitution Failure Is Not An Error)

Using `std::enable_if` to select functions based on type traits.

```cpp
#include <type_traits>
#include <iostream>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
printNumber(T value) {
    std::cout << "Integer: " << value << std::endl;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
printNumber(T value) {
    std::cout << "Float: " << value << std::endl;
}
```

