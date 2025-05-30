#include <iostream>
using namespace std;

class Point

{
private:
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void display()
    {
        cout << "x = " << x << " y = " << y << endl;
    }

    Point &operator+=(Point &p)
    {
        this->x += p.x;
        this->y += p.y;
        return *this;
    }

    int &operator[](int index)
    {
        if (index == 0)
            return x;
        else
            return y;
    }

    Point operator()(int x)
    {
        return Point(this->x * x, this->y * x);
    }
};


int main()
{
    Point p1(10, 20);
    Point p2(30, 40);
    Point p3(15, 30);
    p1 += p2 += p3;
    p1.display();
    p2.display();
    p3.display();

    cout << "p1[0] = " << p1[0] << endl;
    cout << "p1[1] = " << p1[1] << endl;

    p1[0] = 50;

    cout << "p1[0] = " << p1[0] << endl;

    Point p4 = p1(2);
    p4.display();

    return 0;
}
