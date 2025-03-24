#include <iostream>
#include <string>
using namespace std;
class Animal{
    public:
    void eat(){
        cout<<"eats\n";
    }
    void breathes(){
        cout<<"breathes\n";
    }
};
class Mammal:public Animal{
    public:
    string bloodtype;
    Mammal(){
        bloodtype="warm";
    }
};
class Dog:public Mammal{
    public:
    void tailwag(){
        cout<<"a dog wags it's tail\n";
    }
};
int main()
{
    Animal a1;
    Mammal m1();
    Dog d1;
    d1.tailwag();
    cout<<d1.bloodtype<<endl;
    d1.eat();
    d1.breathes();
     return 0;
}
