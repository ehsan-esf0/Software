#include <iostream>
using namespace std;

int maxInArray(int arr[], int size, int index)
{
    if (index == size - 1)
        return arr[index];                      
    int nextMax = maxInArray(arr, size, index + 1);
    cout << arr[index] << " | " << nextMax << endl;
    return (arr[index] > nextMax) ? arr[index] : nextMax;
}

int main()
{
    int arr[] = {5, 2, 9, 4, 7};
    cout << maxInArray(arr, 5, 0); 
}
