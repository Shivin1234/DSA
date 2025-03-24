#include <iostream>
using namespace std;

bool isprime(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i<=n-1;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void allprimes(int n){
    for(int i=2;i<=n;i++){
        if(isprime(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    allprimes(100);
    return 0;
}
