#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "The local date and time is: " << dt << endl;

    time_t t = time(0) + 100;
    cout << "The time now is: " << ctime(&t) << endl;
    
    
    cout << "The difference between now and t is: " << difftime(now, t) << endl;
}