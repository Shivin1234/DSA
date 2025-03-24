#include <iostream>
using namespace std;

void dectobin(int n){
    int pow=1;
    int binum=0;

    while(n>0){
        int rem=n%2;
        binum=binum+rem*pow;
        n=n/2;
        pow=pow*10;
    }
    cout<<binum<<endl;
}
int main()
{
   dectobin(234);

    return 0;
}
