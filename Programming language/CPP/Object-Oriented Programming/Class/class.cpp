#include <iostream>
#include <string>
#include <vector>
using namespace std;

class person
{
private:
    string name;
    int age;
    vector<person*> friends;

public:
    person(string n, int a)
    {
        name = n;
        age = a;
    }

    ~person()
    {
        cout << "die " << this->name << endl;
    }

    void set_name(string n)
    {
        name = n;
    }

    void set_age(int a)
    {
        age = a;
    }

    int get_age()
    {
        return age;
    }

    string get_name()
    {
        return name;
    }

    void show()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }

    void add_friend(person &p)
    {
        friends.push_back(&p);
    }

    void show_friends()
    {
        for (int i = 0; i < friends.size(); i++)
        {
            cout << friends[i]->get_name() << endl;
        }
        cout << "friend white : " << this->name << endl;
    }
};

int main()
{
    person p("tuan", 18);
    p.show();
    p.set_name("john");
    p.set_age(20);
    p.show();

    person p1("tuan", 18);
    p1.show();
    p1.add_friend(p);
    p1.show_friends();

    return 0;
}