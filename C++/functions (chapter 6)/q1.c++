// #include <iostream>
// using namespace std;

// int product(int a,int b){
//     int prod=-a*b;
//     return prod;
// }
// int main()
// {
//    int p=product(2,5);
//    cout<<"product is = "<<p; 

//     return 0;
// }


#include <iostream>
using namespace std;

int oddeven(int a){
    if(a%2==0){
        cout<<"the number is even";
    }
    else if(a%2!=0){
        cout<<"the number is odd";
    }
}
int main()
{
    int b;
    cout<<"enter a number:";
    cin>>b;
    oddeven(b);
    return 0;
}
