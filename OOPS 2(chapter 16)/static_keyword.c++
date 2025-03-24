#include <iostream>
using namespace std;
void counter(){
    int count=0;
    count++;
    cout<<"count:"<<count<<endl;
}
void staticcounter(){
    static int count=0;  //static variable store the value for last time.
    count++;
    cout<<"count:"<<count<<endl;
}
//static class
class Example{
    public:
       static int x;
};
int Example::x;
class Example2{
    public:
        Example2(){
            cout<<"constructor....\n";
        }
        ~Example2(){
            cout<<"destructor....\n";
        }
};
int main()
{
    counter();
    counter();
    counter();
    staticcounter();
    staticcounter();
    staticcounter();
    Example e1;
    Example e2;
    Example e3;
    cout<<e1.x++<<endl;
    cout<<e2.x++<<endl;
    cout<<e3.x++<<endl;
    int a=0;
    if(a==0){
       static Example2 eg1;
    }
    cout<<"code ending...\n";
    return 0;
}
