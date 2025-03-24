#include <iostream>
using namespace std;

void spiralmatrix(int arr[4][4],int n,int m){
    int startrow=0,startcolumn=0;
    int endrow=n-1,endcolumn=m-1;
    while(startrow<=endrow && startcolumn<=endcolumn){
    //top
    for(int j=startcolumn;j<=endcolumn;j++){
        cout<<arr[startrow][j]<<" ";
    }
    //right
    for(int i=startrow+1;i<=endrow;i++){
        cout<<arr[i][endcolumn]<<" ";
    }
    //bottom
    for(int j=endcolumn-1;j>=startcolumn;j--){
        if(startrow==endrow){
            break;
        }
        cout<<arr[endrow][j]<<" ";
    }
    //left
    for(int i=endrow-1;i>=startrow+1;i--){
        if(startcolumn==endcolumn){
            break;
        }
        cout<<arr[i][startcolumn]<<" ";
    }
    startrow++;startcolumn++;
    endrow--;endcolumn--;
    }
    cout<<endl;
}
int main()
{
   int arr[4][4]={{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    spiralmatrix(arr,4,4);
    return 0;
}