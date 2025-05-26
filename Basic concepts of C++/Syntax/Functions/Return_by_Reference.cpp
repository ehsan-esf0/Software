#include <iostream>
#include <string>
#include <vector>
using namespace std;

int& getElement(int arr[], int index) {
    return arr[index];
}
// int& badFunction() {
//     int x = 5;
//     return x;  // ❌ 
// }

class Person {
    string name;
public:
    string& getName() {
        return name;
    }
};


int main() {
    int numbers[3] = {10, 20, 30};
    getElement(numbers, 1) = 99;  
    cout << numbers[1] << endl;  

    Person p1;
    p1.getName() = "ehsan";
    cout << p1.getName() << endl;

}