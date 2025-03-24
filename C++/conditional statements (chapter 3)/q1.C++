#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"enter a number:";
    cin>>a;
    if(a<0){
        cout<<"the number entered is negetive";
    }
    else if(a>0){
        cout<<"the number entered is positive";
    }
    else if(a==0){
        cout<<"the number entered is zero";
    }
    return 0;
} 

