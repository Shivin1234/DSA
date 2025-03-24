#include <iostream>
using namespace std;
int printarray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
   int arr[]={1,2,3,4,5,6,7,8,9,10};
   int n=sizeof(arr)/sizeof(int);
   int start=0;
   int end=n-1; 
    while(start<=end){
       swap(arr[start],arr[end]);                             //int temp=arr[start];
                                                              //arr[start]=arr[end];
                                                              //arr[end]=temp;
        start++;
        end--;
    }
    printarray(arr,n);
    return 0;
}
