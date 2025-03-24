#include <iostream>
using namespace std;
class Parent{
    public:
        void show(){
            cout<<"parent class show....\n";
        }
        virtual void hello(){
            cout<<"parent hello.....\n";
        }
};
class Child:public Parent{
    public:
        void show(){
            cout<<"child class show....\n";
        }
        void hello(){
            cout<<"child hello.....\n";
        }
};
int main()
{
    Child c1;
    Parent *ptr;
    ptr=&c1;
    ptr->hello();
    
    return 0;
}