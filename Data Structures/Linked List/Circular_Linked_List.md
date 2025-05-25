## 📘 Circular Linked List 

---

### 🔄 What is a Circular Linked List?

A **Circular Linked List** is a variation of a linked list where the **last node points back to the first node**, forming a **circle** 🔁.

There is **no `NULL`** in the last node's `next` pointer (in singly circular) or first/last node’s `prev/next` (in doubly circular).

---

### 🧱 Node Structure

#### 🟢 Singly Circular Node:

```cpp
struct Node {
    int data;
    Node* next;
};
```

#### 🔵 Doubly Circular Node:

```cpp
struct Node {
    int data;
    Node* next;
    Node* prev;
};
```

---

### 🧭 Visualization

#### 🔹 Singly Circular Linked List:

```
[10] → [20] → [30]
 ↑                 ↓
 └──────←──────────┘
```

* `tail->next` points back to `head`
* No `nullptr` involved

#### 🔸 Doubly Circular Linked List:

```
[10] ⇄ [20] ⇄ [30]
 ↑                 ↓
 └────←──────→─────┘
```

* Both `next` and `prev` create a full circle

---

### ✅ Advantages

📌 No need to reset pointer to head while looping
📌 Good for applications like round-robin scheduling
📌 Can traverse endlessly from any node
📌 Efficient insertion/deletion at head or tail (especially with tail pointer)

---

### ❌ Disadvantages

⚠️ More complex to implement than singly linked lists
⚠️ Risk of infinite loops if stop condition isn't handled correctly
⚠️ Harder to debug compared to normal linked lists

---

### 🔍 Use Cases

* 🔁 **Round-Robin CPU scheduling**
* 🎮 **Multiplayer game loops**
* 🎵 **Media playlists**
* 🕹️ **Circular buffers**

---

### 🧪 Operations

| Operation      | Time Complexity  |
| -------------- | ---------------- |
| Insert at head | O(1)             |
| Insert at tail | O(1) (with tail) |
| Search         | O(n)             |
| Delete node    | O(n)             |
| Traverse       | O(n)             |

---

### 🔄 Difference Table

| Feature             | Singly | Doubly | Circular Singly | Circular Doubly |
| ------------------- | ------ | ------ | --------------- | --------------- |
| `prev` pointer      | ❌      | ✅      | ❌               | ✅               |
| Last node points to | NULL   | NULL   | Head            | Head & Tail     |
| Bi-directional      | ❌      | ✅      | ❌               | ✅               |
| Memory use          | Low    | High   | Low             | Higher          |

---

### ✏️ Sample Code Snippet

```cpp
// Append to circular singly linked list
void append(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}
```

---

### 📎 Tips for Exams

✅ Always check base case (`tail == nullptr`)
✅ Be careful to avoid infinite loops
✅ Tail is key for O(1) insertion at end
✅ Print using `do-while` for proper traversal

---

### 🎓 Summary

> A **circular linked list** connects the last node back to the first, creating an efficient loop structure with no true "end". It's widely used where cyclic behavior is needed, like round-robin task rotation.

