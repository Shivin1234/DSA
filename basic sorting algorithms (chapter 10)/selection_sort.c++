#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i;j<n;j++){
                if(arr[j]<arr[minindex]){
                    minindex=j;
                }
        }
            swap(arr[i],arr[minindex]);
    }
    print(arr,n);
}
int main()
{
    int arr[]={5,4,1,3,2};
    print(arr,5);
    return 0;
}
