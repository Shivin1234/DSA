#include <iostream>
#include <string>
using namespace std;
class Animal{
    public:
    string colour;
    void eat(){
        cout<<"eats\n";
    }
    void breath(){
        cout<<"breathes\n";
    }
};
class Fish:public Animal{
    public:
    int fins;
    void swim(){
        cout<<"swims\n";
    }
};
int main()
{
    Animal a1;
    Fish f1;
    f1.fins=4;
    cout<<f1.fins<<"\n";
    f1.swim();
    f1.breath();
    f1.eat();
    a1.colour="orrange";
    cout<<a1.colour<<"\n";
    a1.breath();
    a1.eat();
     return 0;
}
