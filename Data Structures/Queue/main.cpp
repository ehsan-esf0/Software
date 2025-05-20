#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<int> number(10);
    number.add(3);
    number.add(5);
    number.add(7);
    number.add(18);
    number.add(2);

    number.print();

    number.remove();

    number.print();
}