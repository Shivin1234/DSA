#include <iostream>
using namespace std;

void bintodec(int n){
    int decnum=0;
    int pow=1;

    while(n>0){
        int lastdig=n%10;
        decnum=decnum+lastdig*pow;
        pow=pow*2;
        n=n/10;
    }
    cout<<decnum<<endl;
}
int main()
{
   bintodec(10011);

    return 0;
}
