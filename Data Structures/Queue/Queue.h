#include "QueueException.h"

template <typename T>
class Queue
{
private:
    T *a;
    int front;
    int rear;
    int size;
    unsigned int capacity;

public:
    Queue(int c)
    {
        capacity = c;
        a = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    Queue(const Queue &q)
    {
        capacity = q.capacity;
        a = new T[capacity];
        front = q.front;
        rear = q.rear;
        size = q.size;
        for (int i = 0; i < capacity; i++)
        {
            a[i] = q.a[i];
        }
    }

    Queue &operator=(const Queue &q)
    {
        if (this != &q)
        {
            delete[] a;
            capacity = q.capacity;
            front = q.front;
            rear = q.rear;
            size = q.size;
            a = new T[capacity];
            for (int i = 0; i < capacity; i++)
            {
                a[i] = q.a[i];
            }
        }
        return *this;
    }

    ~Queue()
    {
        delete[] a;
    }

    bool isFull() const
    {
        return capacity == size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    void add(T item)
    {
        if (isFull())
        {
            throw QueueException("Queue is full");
        }

        rear = (rear + 1) % capacity;

        a[rear] = item;
        size += 1;
    }

    void remove()
    {
        if (isEmpty())
        {
            throw QueueException("Queue is empty");
        }

        front = (front + 1) % capacity;
        size--;
    }

    T frontValue() const
    {
        if (isEmpty())
        {
            throw QueueException("Queue is empty");
        }
        return a[front];
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void clear()
    {
        front = 0;
        rear = -1;
        size = 0;
    }

    void print() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; ++i)
        {
            int index = (front + i) % capacity;
            cout << a[index] << ' ';
        }
        cout << '\n';
    }

    bool operator==(const Queue &other) const
    {
        if (size != other.size || capacity != other.capacity)
            return false;
        for (int i = 0; i < size; ++i)
        {
            int index1 = (front + i) % capacity;
            int index2 = (other.front + i) % other.capacity;
            if (a[index1] != other.a[index2])
                return false;
        }
        return true;
    }

    bool operator!=(const Queue &other) const
    {
        return !(*this == other);
    }
};
