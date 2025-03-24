#include <iostream>
using namespace std;
//abstract class
class Shape{
    public:
    virtual void draw()=0;   //pure virtual function
};
class Circle:public Shape{
    public:
    void draw(){
        cout<<"shape is circle....\n";
    }
};
class Square:public Shape{
    public:
    void draw(){
        cout<<"shape is square....\n";
    }
};

int main()
{
    Circle c1;
    Square s1;
    c1.draw();
    s1.draw();
    return 0;
}
