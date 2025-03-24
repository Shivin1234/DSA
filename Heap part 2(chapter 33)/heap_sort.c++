#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void heapify(int i,vector<int> &arr,int n){
    int l=2*i+1;
    int r=2*i+2;
    int max=i;
    if(l < n && arr[l] > arr[max]){       //for descending order arr[l] < arr[max]
        max=l;
    }
    if(r < n && arr[r] > arr[max]){       //for descending order arr[r] < arr[max]
        max=r;
    }
    if(max!=i){
        swap(arr[max],arr[i]);
        heapify(max,arr,n);
    }
}
void heapsort(vector<int> &arr){
    int n=arr.size();
    //step 1: build maxheap
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,arr,n);
    }
    //step 2: taking elements to correct position
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}
int main(){
    vector<int> arr={1,4,2,5,3};
    heapsort(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}



