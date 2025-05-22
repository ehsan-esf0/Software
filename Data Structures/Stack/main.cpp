#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> number;
    number.push(1);
    number.push(5);
    number.push(7);
    number.push(23);
    number.push(2);

    number.print();

    number.pop();

    number.print();
}