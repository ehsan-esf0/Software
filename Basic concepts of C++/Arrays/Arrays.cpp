#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main()
{
    // linear array
    int numbers[10];

    numbers[0] = 8;
    numbers[1] = 2;
    numbers[2] = 4;
    numbers[3] = 6;

    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30};
    int arr3[5] = {};

    // Multidimensional array
    int matrix[3][4];
    matrix[0][0] = 5;


    // array
    std::array<int, 5> arr4 = {1, 2, 3, 4, 5};

    arr4[0] = 10;
    arr4.at(2) = 30;

    // vector
    std::vector<int> v = {1, 2, 3};
    v.push_back(4);
    v[0] = 10;

    // char* vs char[]
    char* str = "Hello";
    char str2[] = "Hello";

    str[0] = 'H'; // char* can be modified
    str2[0] = 'H'; // char[] cannot be modified
    
    cout << str << endl;
    cout << str2 << endl;


    
    int* dynamicArr = new int[10];
    delete[] dynamicArr; 
}