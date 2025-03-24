#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    bool prime=true;
    
    for(int x=2;x<n;x++){
        if(n%x==0){
            prime=false;
            break;
        }
    }
    if(prime==true){
        cout<<"enterd number is prime"<<"\n";
    }
    else{
        cout<<"entered number is not prime"<<"\n";
    }    
    return 0;
}