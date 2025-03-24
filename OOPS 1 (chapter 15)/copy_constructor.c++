#include <iostream>
#include <string>
using namespace std;
class Car {
    public:
        string name;
        string colour;
        int *mileage;

    Car(string name,string colour){
        this->name=name;
        this->colour=colour;
        mileage=new int;
        *mileage=12;
    }
    Car(Car &original){
        cout<<"copying original to new......\n";
        name=original.name;
        colour=original.colour;
        mileage=new int;
        *mileage=*original.mileage;
    }
    ~Car(){
        cout<<"deleting object....\n";
        if(mileage!=NULL){
            delete mileage;
            mileage=NULL; 
        }
    }
};
int main(){
    Car c1("Range Rover","Black");
    cout<<c1.name<<endl;
    cout<<c1.colour<<endl;
    cout<<*c1.mileage<<endl;
    return 0;
}
