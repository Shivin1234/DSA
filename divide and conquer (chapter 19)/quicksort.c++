#include <iostream>
#include <vector>
using namespace std;
int partition(int arr[],int si,int ei){
    int i=si-1;
    int pivot=arr[ei];

    for(int j=si;j<ei;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;
    
}
void quicksort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int pvtidx=partition(arr,si,ei);
    quicksort(arr,si,pvtidx-1);  //left half
    quicksort(arr,pvtidx+1,ei); //right half
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[6]={6,3,7,5,2,4};
    int n=6;
    quicksort(arr,0,n-1);
    printarr(arr,n);
    return 0;
}