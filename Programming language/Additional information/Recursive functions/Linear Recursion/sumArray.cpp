#include <iostream>
using namespace std;

int sumArray(int arr[], int x, int n)
{
    if (n == x)
    {
        return arr[x];
    }
    return arr[n] + sumArray(arr, x, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << sumArray(arr, 2, 7) << endl;
}