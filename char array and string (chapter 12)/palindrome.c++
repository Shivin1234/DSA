#include <iostream>
#include <cstring>
using namespace std;
bool palindrome(char word[],int n){
    int start=0,end=n-1;
    while(start<=end){
        swap(word[start],word[end]);
        start++;
        end--;
    }
        if(word[start]==word[end]){
            cout<<"valid palindrome"<<"\n";
            return true;
        }
        else{
            cout<<"not a valid palindrome"<<"\n";
            return false;
        }
    }

int main()
{
    char word[]="racecar";
    cout<<palindrome(word,strlen(word));
    return 0;
}
