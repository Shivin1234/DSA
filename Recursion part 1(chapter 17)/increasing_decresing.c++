#include <iostream>
using namespace std;
//decreasing order
void print(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    print(n-1);
    cout<<endl;
    }
//increasing order
void print1(int n){
    if(n==0){
        return;
    }
        print1(n-1);
        cout<<n<<" ";
    
}

int main()
{
   print(8);
   print(10);
    return 0;
}
