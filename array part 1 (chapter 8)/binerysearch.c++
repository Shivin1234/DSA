#include <iostream>
using namespace std;
int binerysearch(int *arr,int n,int key){
    int start=0;
    int end=n-1;
    while(start<=end){
    int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
            }
        else if(arr[mid]<key){
            start=mid+1;
            }
        else if(arr[mid]>key){
            end=mid-1;
            }
        cout<<endl;
    }
    return -1;
}
int main()
{
    int arr[]={2,4,6,8,10,12,14,16,18,20};
    int n=sizeof(arr)/sizeof(int);
    cout<<binerysearch(arr,n,20);
    return 0;
}
