#include<iostream>
using namespace std;
int main()
{
    int a,b,c,total,tax;
    cout<<"enter the cost of pencil:";
    cin>>a;
    cout<<"enter the cost of pen:";
    cin>>b;
    cout<<"enter the cost of eraser:";
    cin>>c;
    total=a+b+c;
    cout<<"the total cost of all the items is:"<<total<<endl;
    tax=(total*18)/100+total;
    cout<<"total cost after GST is:"<<tax<<endl;
} 
