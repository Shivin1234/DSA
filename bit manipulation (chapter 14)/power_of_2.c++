#include <iostream>
using namespace std;

int powerof2(int num){
    if(!(num & (num-1))){
        cout<<"the number is power of 2"<<endl;
    }
    else{
        cout<<"the number is not the power of 2"<<endl;
    }
}

int main(){
    powerof2(10);
    powerof2(32);
    powerof2(18);
    powerof2(64);
    return 0; 
}