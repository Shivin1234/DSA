#include <iostream>
using namespace std;
void subarraysum(int *arr,int n){
    int maxsum=INT16_MIN;
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            int sum=0;
            for(int i=start;i<=end;i++){
                sum=sum+arr[i];
            }
            cout<<sum<<" ";
            maxsum=max(maxsum,sum);
        }
        cout<<endl;
    }
    cout<<"maximum subarray sum is :"<<maxsum<<endl;
}
// more optimized solution
void subarraysum2(int *arr,int n){
    int maxsum=INT16_MIN;
    for(int start=0;start<n;start++){
            int sum=0;
        for(int end=start;end<n;end++){
                sum=sum+arr[end];
            maxsum=max(maxsum,sum);
        }
    }
    cout<<"maximum subarray sum is :"<<maxsum<<endl;
}
int main()
{
    int arr[]={2,-3,6,-5,4,2};
    int n=sizeof(arr)/sizeof(int);
    subarraysum(arr,n);
    subarraysum2(arr,n);
    return 0;
}



