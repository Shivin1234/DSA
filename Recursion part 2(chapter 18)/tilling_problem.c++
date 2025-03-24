//problem is to calculate number of ways to palce tile of 2*1 size in 2*n size of board.
#include <iostream>
using namespace std;
int TP(int n){
    if(n==0 || n==1){
        return 1;
    }
    //vertical
    int ans1=TP(n-1);
    //horizontal
    int ans2=TP(n-2);
    return ans1+ans2;
    
}
int main()
{
    cout<<TP(5);
    return 0;
}
