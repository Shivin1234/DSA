#include <iostream>
using namespace std;
int updatebit(int num,int i,int val){
    num=num & ~(1<<i);
    num=num | (val<<i);
    cout<<num<<endl;
}

int main(){
    updatebit(7,3,1);
    updatebit(7,2,0);    
    return 0; 
}