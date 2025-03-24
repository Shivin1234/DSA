#include <iostream>
#include <string>
using namespace std;
class Animal{
    public:
    void eat(){
        cout<<"eats\n";
    }
    void breath(){
        cout<<"breathes\n";
    }
};
class Bird:public Animal{
    public:
    void fly(){
        cout<<"birds can fly\n";
    }
};
class Mammal:public Animal{
    public:
    void walk(){
        cout<<"mammals can walk\n";
    }
};
int main()
{
    Bird b1;
    Mammal m1;
    m1.eat();
    m1.breath();
    m1.walk();
    b1.eat();
    b1.breath();
    b1.fly();
     return 0;
}
