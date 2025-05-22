#include <iostream>
#include <string>

using namespace std;

class StackException : exception
{
private:
    string message;
public:
    StackException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
