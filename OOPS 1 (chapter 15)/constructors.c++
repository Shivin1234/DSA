#include <iostream>
#include <string>
using namespace std;

class Car{
string name;
string colour;

public:
    Car(){
        cout<<"constructor without parameter.\n";
    }

    Car(string name,string colour){       //constructor.Its name is same as class name.
        cout<<"constructor with parameters.\n";
        this->name=name;  //this is a pointer which bhelp us to distinguish between class variable and constructor variable.
        this->colour=colour;
    }
    void start(){
        cout<<"the car has started....\n";
    }
    void stop(){
        cout<<"the car has stopped\n";
    }
    string getname(){
        return name;
    }
    string getcolour(){
        return colour;
    }

};
int main()
{
    Car c2;
    Car c1("Range Rover","Black");  //constructor is automatically called as soon as object is created.
    cout<<"Car is:"<<c1.getname()<<"\n";
    cout<<"Car colour is:"<<c1.getcolour()<<"\n";
    return 0;
}
