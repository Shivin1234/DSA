#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter a three digit number:";
    cin>>n;
    int num=n;
    int dig1=num%10;
    num/=10;
    int dig2=num%10;
    num/=10;
    int dig3=num%10;
    int cubesum=dig1*dig1*dig1 + dig2*dig2*dig2 + dig3*dig3*dig3;
    if(cubesum==n){
        cout<<"entered number is a armstrong number";
    }
    else{
        cout<<"the entered number is not a armstrong number";
    }
    return 0;
} 