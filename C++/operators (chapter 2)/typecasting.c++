#include<iostream>
using namespace std;
int main()
{
    float PI=3.14;
    cout<<(10/3)<<",";
    cout<<(10/3.0)<<",";
    cout<<('A'+1)<<",";
    cout<<int('a')<<",";
    cout<<int(PI)<<",";
    cout<<((float)10/3)<<",";
    cout<<(char)('A'+1)<<",";
    cout<<(bool)3+2;   //bool return value 1 for all non zero digits as true and return value 0 for all zero digit
return 0;
}