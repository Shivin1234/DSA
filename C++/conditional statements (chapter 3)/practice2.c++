#include<iostream>
using namespace std;
int main()
{
    int income;
    cout<<"enter your income:";
    cin>>income;
    if(income<=500000){
        cout<<"income tax(0%) in is Rs 0";
    }
    else if(500000<income<1000000){
        cout<<"income tax(20%)  is Rs "<<(income*20/100);
    }
    else if(income>1000000){
        cout<<"income tax(30%) is Rs "<<(income*30/100);
    }
    return 0;
}
