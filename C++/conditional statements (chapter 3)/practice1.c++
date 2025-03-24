#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"enter value of first number:";
    cin>>a;
    cout<<"enter value of second number:";
    cin>>b;
    if(a>b){
        cout<<"a is greater than b";
    }
    else if(b>a){
        cout<<"b is greater than a";
    }
    else{
        cout<<"wrong input";
    }
    return 0;
} 

