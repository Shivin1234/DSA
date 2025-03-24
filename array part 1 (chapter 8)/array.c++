#include <iostream>
using namespace std;
int main()
{
    int roll[50];   //will give garbage values.

    int marks[50]={1,2,3};   //if we initialize some values to array then the rest are assigned to be 0.
    cout<<marks[0]<<" ";
    cout<<marks[1]<<" ";
    cout<<marks[2]<<" ";
    cout<<marks[15]<<endl;
    
    int percentage[]={1,2,3};  //another method of declaring array.
    cout<<percentage[0]<<" ";
    cout<<percentage[1]<<" ";
    cout<<percentage[2]<<" ";
    cout<<percentage[7]<<endl;
    return 0;
}