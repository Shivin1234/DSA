#include <iostream>
using namespace std;

int sum(int a,int b){
    cout<<(a+b)<<endl;
    return 0;
}
double sum(double a,double b){
    cout<<(a+b)<<endl;
    return 0;
}
int main()
{
    sum(2,6);
    sum(4.6,8.7);
    sum(4,7);
    return 0;
}
