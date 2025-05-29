# 📘 C++ Time Handling: Complete Notes

## 1. ⏳ Legacy Time Library: `<ctime>`

### 📌 Overview:

* Origin: Inherited from the C standard library (`<time.h>`)
* Simple and straightforward
* Works primarily with **seconds resolution**

### 📌 Key Types:

* `time_t`
  Represents calendar time (usually seconds since Epoch, i.e., 1970-01-01 00:00:00 UTC)

* `struct tm`
  A structure representing broken-down time:

  ```cpp
  struct tm {
      int tm_sec;   // seconds [0,60]
      int tm_min;   // minutes [0,59]
      int tm_hour;  // hours [0,23]
      int tm_mday;  // day of the month [1,31]
      int tm_mon;   // months since January [0,11]
      int tm_year;  // years since 1900
      int tm_wday;  // days since Sunday [0,6]
      int tm_yday;  // days since Jan 1 [0,365]
      int tm_isdst; // Daylight Saving Time flag
  };
  ```

### 📌 Common Functions:

| Function              | Description                                  |
| --------------------- | -------------------------------------------- |
| `time(time_t*)`       | Get the current time                         |
| `localtime()`         | Convert `time_t` to `struct tm` (local time) |
| `gmtime()`            | Convert `time_t` to `struct tm` (UTC time)   |
| `asctime(struct tm*)` | Convert `tm` to human-readable string        |
| `ctime(time_t*)`      | Combines `localtime` + `asctime`             |
| `difftime(t1, t2)`    | Return difference in seconds (double)        |

### ✅ Example:

```cpp
#include <iostream>
#include <ctime>

int main() {
    std::time_t now = std::time(nullptr);
    std::cout << "Current time: " << std::ctime(&now);

    std::tm* local = std::localtime(&now);
    std::cout << "Year: " << 1900 + local->tm_year << ", Month: " << 1 + local->tm_mon << '\n';
}
```

---

## 2. ⏱ Modern Time Library: `<chrono>` (C++11+)

### 📌 Why Use `<chrono>`?

* High precision (nanoseconds!)
* Type safety using templates
* Supports multiple time units and clocks

### 📌 Key Concepts:

| Concept                   | Description                            |
| ------------------------- | -------------------------------------- |
| `std::chrono::duration`   | Represents time span (e.g., 5 seconds) |
| `std::chrono::time_point` | Represents a specific point in time    |
| `std::chrono::clock`      | Provides current time and time points  |

---

### ⏲️ Main Clocks:

| Clock                   | Description                                          | Use Case                         |
| ----------------------- | ---------------------------------------------------- | -------------------------------- |
| `system_clock`          | Real-world clock (can be converted to/from `time_t`) | Timestamps, logs                 |
| `steady_clock`          | Monotonic clock (never adjusted)                     | Measuring durations/benchmarking |
| `high_resolution_clock` | Highest available precision clock                    | High-precision timing            |

---

### ⏳ Duration Units:

```cpp
std::chrono::hours
std::chrono::minutes
std::chrono::seconds
std::chrono::milliseconds
std::chrono::microseconds
std::chrono::nanoseconds
```

---

### ✅ Example: Measure Execution Time

```cpp
#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // Code to measure
    for (int i = 0; i < 1e6; ++i);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
}
```

---

### ✅ Example: Sleep and Measure

```cpp
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    using namespace std::chrono;

    auto start = steady_clock::now();
    std::this_thread::sleep_for(seconds(2));
    auto end = steady_clock::now();

    auto diff = duration_cast<milliseconds>(end - start);
    std::cout << "Slept for " << diff.count() << " milliseconds\n";
}
```

---

### 🔄 Convert Between Units:

```cpp
auto ns = duration_cast<nanoseconds>(seconds(1));
auto ms = duration_cast<milliseconds>(ns);
```

---

## 3. 📊 Summary Table: `<ctime>` vs `<chrono>`

| Feature                  | `<ctime>`          | `<chrono>`                  |
| ------------------------ | ------------------ | --------------------------- |
| Accuracy                 | Seconds            | Nanoseconds or higher       |
| Style                    | C-style            | Modern C++ (template-based) |
| Type Safety              | Weak               | Strong                      |
| Use Case                 | Simple time/dates  | Precise durations & timing  |
| Time Manipulation        | Manual (with `tm`) | Easy with durations         |
| Recommended for New Code | ❌                  | ✅                           |

---

## 4. 🎯 Practical Use Cases:

| Use Case                           | Recommended Library                        |
| ---------------------------------- | ------------------------------------------ |
| Get current time                   | `<chrono>` or `<ctime>`                    |
| Format/display human-readable time | `<ctime>`                                  |
| Measure function run time          | `<chrono>` (with `steady_clock`)           |
| Sleep/delay code execution         | `<chrono>` + `std::this_thread::sleep_for` |
| Logging timestamps                 | `<chrono::system_clock>` or `<ctime>`      |
