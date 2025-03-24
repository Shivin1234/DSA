#include<iostream>
using namespace std;

int countinrange(int arr[],int num,int si,int ei){
    int count=0;
    for(int i=si;i<=ei;i++){
            if(arr[i]==num){
                count++;
            }
    }
    return count;
}
int majorityelementrec(int arr[],int si,int ei){
    if(si==ei){
        return arr[si];
    }
    int mid=(si+ei)/2;
    int left=majorityelementrec(arr,si,mid);
    int right=majorityelementrec(arr,mid+1,ei);

    if(left==right){
        return left;
    }
    int leftcount=countinrange(arr,left,si,ei);
    int rightcount=countinrange(arr,right,si,ei);

    return leftcount>rightcount?left:right;
}
int majorityelement(int arr[],int n){
    return majorityelementrec(arr,0,n-1);
}
int main(){
   int arr[]={2,2,1,1,1,2,2};
   int n=7;
   cout<<majorityelement(arr,n)<<endl;
    return 0;
}