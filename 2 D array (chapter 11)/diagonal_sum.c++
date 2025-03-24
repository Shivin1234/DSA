#include <iostream>
using namespace std;

void diagonalsum(int arr[4][4],int n,int m){
    int sum1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                sum1=sum1+arr[i][j];
            }
        }
    }
    cout<<"the sum of 1st diagonal is:"<<sum1<<endl;

    int sum2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==n-i-1){
                sum2=sum2+arr[i][j];
            }
        }
    }
    cout<<"the sum of 2nd diagonal is:"<<sum2<<endl;
    int sum=sum1+sum2;
    cout<<"the sum of both diagonals is:"<<sum<<endl;
}

    //best method for odd matrices because it prevent number to add twice
    void shortcut(int arr[4][4],int n,int m){ 
    int sum3=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                sum3+=arr[i][j];
            }
            else if(j==n-i-1){
                sum3+=arr[i][j];
            }
        }
    }
    cout<<"sum is :"<<sum3<<endl;
    }


    //more efficient method
   void efficient(int arr[4][4],int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i][i];
            if(i!=n-i-1){
                sum+=arr[i][n-i-1];
            }
        }
        cout<<"sum is :"<<sum<<endl;
   }
int main()
{
    int arr[4][4]={{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    diagonalsum(arr,4,4);
    efficient(arr,4);
    shortcut(arr,4,4);
    return 0;
}
