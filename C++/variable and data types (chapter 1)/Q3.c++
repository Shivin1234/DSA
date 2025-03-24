#include<iostream>
using namespace std;
int main()
{
   float p,r,t,si;
   cout<<"enter the value of principle:";
   cin>>p;
   cout<<"enter the rate:";
   cin>>r;
   cout<<"enter the amount of time:";
   cin>>t;
   si=(p*r*t)/100;
   cout<<"the simple interest of the given values is:"<<si<<endl;
    return 0;
} 
