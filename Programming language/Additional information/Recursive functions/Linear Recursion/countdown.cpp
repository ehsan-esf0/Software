#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) {
        cout << "Boom!\n";
        return;
    }
    cout << n << "\n";  
    countdown(n - 1);  
}

int main() {
    countdown(5);
}
