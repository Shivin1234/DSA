// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[5]={54,65,76,45,67};
//     int n=sizeof(arr)/sizeof(int);

//     for(int i=0;i<=n-1;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;

//     return 0;
// }


#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter no. of elements in array:";
    cin>>n;

    int arr[n];
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}