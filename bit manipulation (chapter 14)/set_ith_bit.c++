#include <iostream>
using namespace std;

int getithbit(int num,int i){
    int bitmask=1<<i;
    if(!(num & bitmask)){
        return 0;
    }
    else{
        return 1;
    }
}

int setithbit(int num,int i){
    int bitmask=1<<i;
    return(num | bitmask);
}

int clearithbit(int num,int i){
    int bitmask=~(1<<i);
    return(num & bitmask);
}

int main()
{
    cout<<clearithbit(6,3)<<"\n";
    cout<<setithbit(6,1)<<"\n";
    cout<<getithbit(6,2)<<"\n";
    return 0;
}

