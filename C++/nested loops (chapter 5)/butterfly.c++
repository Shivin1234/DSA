#include <iostream>
using namespace std;
int main()
{
    int n=4;
    int i,j;
    for(i=1;i<=n;i++){
        //star
        for(j=1;j<=i;j++){
            cout<<"*";
        }
        //space
        for(j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        //star
        for(j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    //second half
    for(i=n;i>=1;i--){
        //star
        for(j=1;j<=i;j++){
            cout<<"*";
        }
        //space
        for(j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        //star
        for(j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
