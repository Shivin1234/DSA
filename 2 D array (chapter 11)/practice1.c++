#include <iostream>
using namespace std;

void count(int arr[2][3],int n,int m){
    int count7=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==7){
                count7+=1;
            }
        }
    }
    cout<<count7<<endl;
}
int main()
{
    int arr[2][3]={{4,7,8},
                   {8,8,7}};
    count(arr,2,3);              
    return 0;
}
