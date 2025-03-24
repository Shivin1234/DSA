#include <iostream>
using namespace std;

int lastibits(int num,int i){
    int bitmask=(~0)<<i;
    num=num & bitmask;
    cout<<num<<endl;
}

int countsetbits(int num){
    int count=0;
    while(num>0){
        int lastdigit=num & 1;
        count=count+lastdigit;
        num=num>>1;
    }
    cout<<count<<endl;
}
int main()
{
    lastibits(15,2);
    countsetbits(15);
    return 0;
}
