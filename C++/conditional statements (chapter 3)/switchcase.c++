#include<iostream>
using namespace std;
int main()
{
    int a,b;
    char op;
    cout<<"enter value of a:";
    cin>>a;
    cout<<"enter value of b:";
    cin>>b;
    cout<<"enter the operator:";
    cin>>op;
    
    switch(op){
        case '+':cout<<"a + b = "<<(a+b)<<"\n";
                    break;
        case '-':cout<<"a - b = "<<(a-b)<<"\n";
                    break;
        case '*':cout<<"a * b = "<<(a*b)<<"\n";
                    break;
        case '/':cout<<"a / b = "<<(a/b)<<"\n";
                    break;

    }
    return 0;
}