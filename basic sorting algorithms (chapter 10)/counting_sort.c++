#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countingsort(int arr[],int n){
    int freq[100000]={0};
    int minvalue=INT8_MAX , maxvalue=INT8_MIN;
    for(int i=0;i<n;i++){
        minvalue=min(minvalue,arr[i]);
        maxvalue=max(maxvalue,arr[i]);
    }

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=minvalue,j=0;i<=maxvalue;i++){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
    print(arr,n);
}
int main()
{
   int arr[8]={1,4,1,3,2,4,3,7};
   countingsort(arr,8);
    return 0;
}
