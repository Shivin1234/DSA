#include <iostream>
using namespace std;
int main()
{
    int n=5;
    int i,j;
    for(i=1;i<=n;i++){
        //spaces
        for(j=1;j<=n-i;j++){
            cout<<" ";
        }
        //numbers backwards
        for(j=i;j>=1;j--){
            cout<<j;
        }
        //numbers forward
        for(j=2;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}
