//to calculate number of ways n number of friends can be paired or 1 might be single while other are paired.
#include <iostream>
using namespace std;
int friendpairing(int n){
    if(n<=2){
        return n;
    }
    //when friend is single
    int ans1=friendpairing(n-1);
    //when a friend is paired with another friend
    int ans2=(n-1)*friendpairing(n-2); //we multiplied (n-1) because there are (n-1) number of choices to make a pair and (n-2) is written because after making a pair (n-2) elements are left.
    return ans1+ans2;
}
int main()
{
    cout<<friendpairing(4);
    return 0;
}
