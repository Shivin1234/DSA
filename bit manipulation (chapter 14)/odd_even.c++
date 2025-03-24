#include <iostream>
using namespace std;

int oddeven(int num){
    if(!(num & 1)){
        cout<<"the number is even \n";
    }
    else{
        cout<<"the number is odd \n";
    }
}
int main(){
    oddeven(10);
    return 0;
}