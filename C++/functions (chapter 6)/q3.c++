#include <iostream>
using namespace std;

int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
int bincoeff(int n,int r){
    int val1=factorial(n);
    int val2=factorial(r);
    int val3=factorial(n-r);

    int result=val1/(val2*val3);
}

int main()
{
    int a,b;
    cout<<"enter values of n and r:\n";
    cin>>a>>b;
    cout<<bincoeff(a,b);
    return 0;
}
