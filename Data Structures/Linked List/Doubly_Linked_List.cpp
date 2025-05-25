#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node() : next(nullptr), prev(nullptr) {}
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
public:
    Node<T>* header;
    Node<T>* trailer;
    int size;

public:
    DoublyLinkedList() {
        header = new Node<T>();
        trailer = new Node<T>();
        header->next = trailer;
        trailer->prev = header;
        size = 0;
    }

    ~DoublyLinkedList() {
        while (header->next != trailer) {
            removeNode(header->next);
        }
        delete header;
        delete trailer;
    }

    void addNode(T newVal, Node<T>* prevNode, Node<T>* nextNode) {
        Node<T>* newNode = new Node<T>(newVal);
        newNode->next = nextNode;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        nextNode->prev = newNode;
        size++;
    }

    void removeNode(Node<T>* delNode) {
        if (delNode == header || delNode == trailer) {
            return;
        }
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delete delNode;
        size--;
    }

    int getSize() const {
        return size;
    }

    void printList() const {
        Node<T>* current = header->next;
        while (current != trailer) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void addToFront(T data) {
        addNode(data, header, header->next);
    }

    void addToBack(T data) {
        addNode(data, trailer->prev, trailer);
    }

    void removeFromFront() {
        if (size > 0) {
            removeNode(header->next);
        }
    }

    void removeFromBack() {
        if (size > 0) {
            removeNode(trailer->prev);
        }
    }
};

int main() {
    DoublyLinkedList<int> list;
    list.addToFront(1);
    list.addToFront(2);
    list.addToFront(3);
    list.printList(); 
}