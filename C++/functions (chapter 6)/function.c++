#include<iostream>
using namespace std;

void sayhello(){
    cout<<"hello :)\n";
}
void assistant(){
    sayhello();
    cout<<"work done \n";
}

int main()
{
    assistant();
    return 0;
} 
