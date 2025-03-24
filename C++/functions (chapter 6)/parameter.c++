#include<iostream>
using namespace std;

int sum(int a,int b){
    int sum=a+b;
    return sum;
}
int diff(int a,int b){
    int diff=a-b;
    return diff;
}
int main()
{
    int s=sum(6,9);
    cout<<"sum = "<<s<<endl;
    cout<<diff(109,76);
    
    return 0;
} 
