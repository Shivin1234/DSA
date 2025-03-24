#include <iostream>
using namespace std;

int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    cout<<"the factorial of given number is:"<<fact<<endl;
}
int main()
{
    int m;
    cout<<"enter a number:";
    cin>>m;
    factorial(m);
    return 0;
}
