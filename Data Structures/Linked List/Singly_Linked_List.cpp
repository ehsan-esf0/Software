#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node() : next(nullptr) {}
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~SinglyLinkedList()
    {
        while (head != nullptr)
        {
            removeFirst();
        }
    }
    void addFirst(T newVal)
    {
        Node<T> *newNode = new Node<T>(newVal);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr)
        {
            tail = newNode;
        }
        size++;
    }

    void addLastOrMiddle(Node<T> *prevNode, T newVal)
    {
        if (prevNode == nullptr)
        {
            return;
        }
        Node<T> *newNode = new Node<T>(newVal);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = prevNode->next;
            prevNode->next = newNode;
            if (prevNode == tail)
            {
                tail = newNode;
            }
        }
        size++;
    }

    void removeFirst()
    {
        if (head == nullptr)
        {
            return;
        }
        Node<T> *prevHead = head;
        head = head->next;
        if (prevHead == tail)
        {
            tail = nullptr;
        }
        delete prevHead;
        size--;
    }

    void removeLastOrMiddle(Node<T> *prevNode)
    {
        if (head == nullptr)
        {
            return;
        }
        if (prevNode == nullptr || prevNode->next == nullptr)
        {
            return;
        }

        Node<T> *delNode = prevNode->next;
        prevNode->next = delNode->next;
        if (delNode == tail)
        {
            tail = prevNode;
        }
        delete delNode;
        size--;
    }

    int getSize() const
    {
        return size;
    }

    void printList() const
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    SinglyLinkedList<int> list;
    list.addFirst(4);
    list.addFirst(3);
    list.addFirst(2);
    list.addFirst(1);
    list.printList();
    list.removeFirst();
    list.printList();
}
