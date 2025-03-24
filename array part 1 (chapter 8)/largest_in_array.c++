#include <iostream>
using namespace std;
int main()
{
    int arr[5]={5,4,3,9,12};
    int n=sizeof(arr)/sizeof(int);
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<n;i++){
            if(arr[i]>max){
                    max=arr[i];
                    cout<<"the value of max is changed to "<<max<<endl;
            }
           if(arr[i]<min){
        min=arr[i];
    }
    }
    cout<<"maximum value in the array is:"<<max<<"\n";
    cout<<"minimum value in the array is:"<<min;

    return 0;
}