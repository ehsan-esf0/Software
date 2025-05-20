#include <iostream>
#include <exception>
using namespace std;

class QueueException : public exception {
private:
    string message;

public:
    QueueException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
