#include <iostream>
using namespace std;
int binsearch(int arr[],int start,int end,int key){
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    if(arr[mid]==key){
        return mid;
    }else if(arr[mid]>=key){
        return binsearch(arr,start,mid-1,key);
    }else{
        return binsearch(arr,mid+1,end,key);
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(int);
    cout<<binsearch(arr,0,n-1,7);
    return 0;
}
