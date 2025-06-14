### 📚 Common and Popular C++ Libraries (Standard and Third-Party)

| **Library Name**       | **General Use**                               | **Popular Classes/Functions**                                      |
| ---------------------- | --------------------------------------------- | ------------------------------------------------------------------ |
| `<iostream>`           | Standard input/output                         | `std::cin`, `std::cout`, `std::endl`, `std::cerr`                  |
| `<string>`             | String manipulation                           | `std::string`, `length()`, `substr()`, `find()`, `append()`        |
| `<vector>`             | Dynamic arrays                                | `std::vector`, `push_back()`, `size()`, `insert()`, `erase()`      |
| `<list>`               | Doubly-linked lists                           | `std::list`, `push_back()`, `push_front()`, `sort()`               |
| `<deque>`              | Double-ended queues                           | `std::deque`, `push_back()`, `push_front()`, `pop_back()`          |
| `<stack>`              | Stack (LIFO) container                        | `std::stack`, `push()`, `pop()`, `top()`                           |
| `<queue>`              | Queue (FIFO), priority queue                  | `std::queue`, `std::priority_queue`, `push()`, `front()`           |
| `<map>`                | Ordered key-value map                         | `std::map`, `insert()`, `find()`, `[]`, `erase()`                  |
| `<unordered_map>`      | Hash map (faster unordered map)               | `std::unordered_map`, `[]`, `insert()`, `find()`                   |
| `<set>`                | Unique sorted elements                        | `std::set`, `insert()`, `count()`, `find()`                        |
| `<unordered_set>`      | Hash-based set                                | `std::unordered_set`, `insert()`, `count()`, `erase()`             |
| `<bitset>`             | Bit manipulation                              | `std::bitset`, `set()`, `reset()`, `flip()`, `count()`             |
| `<algorithm>`          | General algorithms                            | `sort()`, `reverse()`, `find()`, `binary_search()`, `accumulate()` |
| `<numeric>`            | Numerical algorithms                          | `accumulate()`, `inner_product()`, `partial_sum()`                 |
| `<cmath>`              | Math functions                                | `sqrt()`, `pow()`, `sin()`, `cos()`, `fabs()`                      |
| `<cstdlib>`            | General utilities (conversions, memory, rand) | `rand()`, `atoi()`, `atof()`, `malloc()`, `free()`                 |
| `<ctime>`              | Time and date functions                       | `time()`, `clock()`, `difftime()`, `asctime()`                     |
| `<chrono>`             | Modern time utilities (C++11+)                | `std::chrono::system_clock`, `now()`, `duration`, `sleep_for()`    |
| `<thread>`             | Multithreading                                | `std::thread`, `join()`, `detach()`                                |
| `<mutex>`              | Thread synchronization                        | `std::mutex`, `lock()`, `unlock()`, `std::lock_guard`              |
| `<condition_variable>` | Thread synchronization (conditions)           | `std::condition_variable`, `wait()`, `notify_one()`                |
| `<fstream>`            | File I/O                                      | `std::ifstream`, `std::ofstream`, `open()`, `getline()`, `close()` |
| `<sstream>`            | String-based streams                          | `std::stringstream`, `std::istringstream`, `str()`, `>>`, `<<`     |
| `<tuple>`              | Heterogeneous data container                  | `std::tuple`, `std::get()`, `std::tie()`                           |
| `<array>`              | Fixed-size array                              | `std::array`, `at()`, `size()`, `fill()`                           |
| `<functional>`         | Function objects and wrappers                 | `std::function`, `std::bind`, `std::ref()`                         |
| `<memory>`             | Smart pointers and memory management          | `std::shared_ptr`, `std::unique_ptr`, `make_shared()`              |
| `<typeinfo>`           | Runtime type information (RTTI)               | `typeid`, `type_info`                                              |
| `<exception>`          | Exception handling                            | `try`, `catch`, `throw`, `std::exception`, `what()`                |
| `<cassert>`            | Assertions                                    | `assert()`                                                         |
| `<cctype>`             | Character checks                              | `isalpha()`, `isdigit()`, `tolower()`, `toupper()`                 |
| `<locale>`             | Localization and character traits             | `std::locale`, `use_facet()`, `std::ctype`                         |

---

### 🧩 Popular Third-Party Libraries (Non-Standard)

| **Library**     | **Purpose**                           | **Highlights**                                                  |
| --------------- | ------------------------------------- | --------------------------------------------------------------- |
| **Boost**       | General-purpose utility extensions    | Smart pointers, filesystem, regex, threads, serialization, etc. |
| **OpenCV**      | Computer vision and image processing  | Image/video operations, AI vision tools                         |
| **SFML**        | Multimedia and game development       | Graphics, sound, input/output, window control                   |
| **Qt**          | Cross-platform GUI and app framework  | Powerful GUI, signals/slots, widgets                            |
| **Eigen**       | Linear algebra                        | Fast and elegant matrix/vector math                             |
| **Poco**        | Networking, HTTP servers, utilities   | Lightweight alternative to Boost                                |
| **TBB (Intel)** | Multithreading & parallel programming | Task-based multithreading, scalable parallelism                 |
