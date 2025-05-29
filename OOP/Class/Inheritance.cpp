#include <iostream>
#include <string>
using namespace std;

class Animals
{
protected:
    int age;
    string name;

public:
    Animals(int age, string name)
    {
        this->age = age;
        this->name = name;
        cout << "Animals" << endl;
    }
    ~Animals()
    {
        cout << "Animal is destroyed" << endl;
    }
};

class Dog : public Animals
{
private:
    int numLeg;
    string breed;

public:
    Dog(int age, string name, int numLeg, string breed) : Animals(age, name)
    {
        this->numLeg = numLeg;
        this->breed = breed;
        cout << "Dog" << endl;
    }
    ~Dog()
    {
        cout << "Dog is destroyed" << endl;
    }

    void show()
    {
        cout << "name : " << this->name << endl;
        cout << "age : " << this->age << endl;
        cout << "numLeg : " << this->numLeg << endl;
        cout << "breed : " << this->breed << endl;
    }
};

int main()
{
    Dog d(1, "Dog", 4, "German Shepherd");
}
