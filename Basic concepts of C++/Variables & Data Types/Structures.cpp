#include <iostream>
using namespace std;

struct person
{
    struct birth
    {
        birth() = default;
        birth( int year, int month, int day ) {
            this->year = year;
            this->month = month;
            this->day = day;
        }
        int year;
        int month;
        int day;
    };
    birth birthDate;

    person( string name, string family, int age , birth birthDate) {
        this->name = name;
        this->family = family;
        this->age = age;
        this->birthDate = birthDate;
    }
    string name;
    string family;
    int age;

    void print() {
        cout << name << " " << family << " " << age << endl;
        cout << birthDate.year << " " << birthDate.month << " " << birthDate.day << endl;
    }  
};

int main()
{
    person p1( "Ali" , "Mohammadi" , 24 , {1998, 11, 24} );

    

    person p2{
        "Reza",
        "Rezaei",
        20,
        {1990, 11, 24}
    };

    p1.print();
    p2.print();

}