#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class CircularLinkedList
{
private:
    Node<T> *tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void append(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (!tail)
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() const
    {
        if (!tail)
        {
            throw runtime_error("Cannot print: list is empty.");
        }

        Node<T> *current = tail->next;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        cout << endl;
    }

    void remove(T value)
    {
        if (!tail)
        {
            throw runtime_error("Cannot remove from empty list.");
        }

        Node<T> *current = tail->next;
        Node<T> *prev = tail;
        bool found = false;

        do
        {
            if (current->data == value)
            {
                found = true;
                if (current == tail && current == tail->next)
                {
                    delete current;
                    tail = nullptr;
                }
                else
                {
                    prev->next = current->next;
                    if (current == tail)
                        tail = prev;
                    delete current;
                }
                break;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);

        if (!found)
        {
            throw invalid_argument("Value not found in list.");
        }
    }

    void clear()
    {
        if (!tail)
            return;

        Node<T> *current = tail->next;
        do
        {
            Node<T> *temp = current;
            current = current->next;
            delete temp;
        } while (current != tail->next);

        tail = nullptr;
    }

    ~CircularLinkedList()
    {
        clear();
    }
};
