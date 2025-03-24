//to find number of ways to form a binary string of length n where 2 consecutive ones should not present.
#include <iostream>
using namespace std;
void binarystring(int n,int lastplace,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(lastplace!=1){
        binarystring(n-1,0,ans+'0'); //we put 0 in middle because when we add 0 to the answer then last place become 0.
        binarystring(n-1,1,ans+'1'); //we put 1 in middle because when we add 1 to the answer then last place become 1.
    }else{
        binarystring(n-1,0,ans+'0');
    }
}
int main()
{
    string ans="";
  binarystring(3,0,ans);   
    return 0;
}
