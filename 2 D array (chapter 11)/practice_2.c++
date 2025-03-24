#include <iostream>
using namespace std;

void sum(int arr[3][3],int m,int n){
        int middlesum=0;
        for(int j=0;j<m;j++){
            middlesum+=arr[1][j];
        }
        cout<<"sum of middle row is:"<<middlesum<<endl;
}
int main()
{
    int arr[3][3]={{1,4,9},
                   {11,4,3},
                    {2,2,3}};
    sum(arr,3,3);
    return 0;
}
