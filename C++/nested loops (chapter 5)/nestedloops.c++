#include <iostream>
using namespace std;
int main()
{
int n=5;
    //outer loop
    for(int i=1;i<=n;i++){
        //inner loop
        for(int j=1;j<=n;j++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
