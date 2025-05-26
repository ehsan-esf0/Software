#include <iostream>
using namespace std;

enum color
{
    red,
    green,
    blue,
    yellow
};

enum Day
{
    SUNDAY,    // 0
    MONDAY,    // 1
    TUESDAY,   // 2
    WEDNESDAY, // 3
    THURSDAY,  // 4
    FRIDAY,    // 5
    SATURDAY   // 6
};

enum HttpStatus
{
    OK = 200,
    CREATED = 201,
    ACCEPTED = 202,
    NOT_FOUND = 404
};

enum class Color
{
    Red,
    Green,
    Blue
};

enum name{
    John,
    Peter,
    Mary
};

int main()
{
    color c;
    c = red;
    cout << c << endl;
    c = green;
    cout << c << endl;
    c = blue;
    cout << c << endl;
    c = yellow;
    cout << c << endl;

    cout << "Day of the week is " << Day::SUNDAY << endl;

    HttpStatus status;
    status = HttpStatus::OK;
    cout << status << endl;

    Color color = Color::Red;
    int x = static_cast<int>(c);
    cout << x << endl;
    return 0;
}