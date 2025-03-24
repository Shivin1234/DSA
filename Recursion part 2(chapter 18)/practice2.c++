#include <iostream>
using namespace std;
void alloccurence(int arr[],int i,int n,int key){
    if(i==n){
        return;
    }
    if(arr[i]==key){
        cout<<i<<" ";
    }
    alloccurence(arr,i+1,n,key);
}
int main()
{
    int arr[]={1,2,3,4,2,5,2,6,2,7,2,2,2};
    int n=sizeof(arr)/sizeof(int);
    alloccurence(arr,0,n,2);
    return 0;
}
