#include <iostream>
using namespace std;

int reverse(int n){
    int rev=0;
    while(n>0){
        int lastdig=n%10;
        rev=rev*10+lastdig;
        n=n/10;
    }
    return rev;
}
int palindrome(int num){
    int revnumber=reverse(num);
    if(revnumber==num){
        cout<<"number entered is palindrome";
    }
    else{
        cout<<"number entered is not palindrome";
    }
}
int main()
{
    palindrome(223);
    return 0;
}