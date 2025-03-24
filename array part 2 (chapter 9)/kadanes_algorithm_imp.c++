#include <iostream>
using namespace std;
int maxsubarraysum(int *arr,int n){
    int sum=0;
    int maxsum=INT16_MIN;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        maxsum=max(maxsum,sum);
        if(sum<0){
            sum=0;
        }
    cout<<"maximum sum of subarray is:"<<maxsum<<endl;
    }
}
int main()
{
  int arr[]={2,-3,6,-5,4,2};  
    int n=sizeof(arr)/sizeof(int);
    maxsubarraysum(arr,n);
    return 0;
}
