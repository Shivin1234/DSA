#include <iostream>
using namespace std;
int main(){
    cout<<(3 & 5)<<endl;
    cout<<(3 | 5)<<endl;
    cout<<(3 ^ 5)<<endl;
    cout<<(~6)<<endl; // ~reverses the bits of the number till 8 bits and if the MSB is 1 then number is -ve and if it is 0 then number is +ve.And then we neglect MSB and reverse again the 7 bits and add 1 to it and we get final answer i.e -7.
    cout<<(~0)<<endl;
    cout<<(7<<2)<<endl; //ans=7*2^2=28
    cout<<(7>>2)<<endl; //ans=7/2^2=1
    return 0;
}