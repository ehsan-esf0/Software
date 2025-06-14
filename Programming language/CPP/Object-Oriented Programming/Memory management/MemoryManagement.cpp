#include <iostream>
#include <cstring>

class Person {
private:
    char* name;  
    int age;

public:

    Person() : name(nullptr), age(0) {}


    Person(const char* pname, int page) : age(page) {
        if (pname) {
            name = new char[strlen(pname) + 1];
            strcpy(name, pname);
        } else {
            name = nullptr;
        }
    }


    Person(const Person& other) : age(other.age) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
    }


    Person& operator=(const Person& other) {
        if (this != &other) {
   
            delete[] name;

            age = other.age;

            if (other.name) {
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            } else {
                name = nullptr;
            }
        }
        return *this;
    }

    Person(Person&& other) noexcept : age(other.age) {
        name = other.name;
        other.name = nullptr;
    }

    
    ~Person() {
        delete[] name;
    }

    void print() const {
        std::cout << "Name: " << (name ? name : "No name") << ", Age: " << age << std::endl;
    }
};

int main() {
    Person p1("Alice", 30);
    p1.print();

    Person p2 = p1;  
    p2.print();

    Person p3;
    p3 = p1;         
    p3.print();

    return 0;
}
