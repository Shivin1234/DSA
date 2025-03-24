// #include <iostream>
// using namespace std;
// int main()
// {
//     char arr[5]={'c','o','d','e','\0'};
//     char arr1[]={"code"};
//     cout<<arr[0]<<endl;
//     cout<<arr[1]<<endl;
//     cout<<arr[2]<<endl;
//     cout<<arr[3]<<endl;
//     cout<<arr1<<endl;
//     return 0;
// }


#include <iostream>
#include <cstring>
using namespace std;
void array1(){
        char arr[20];
        cout<<"enter the word to be dispalyed:";
        cin>>arr;
        cout<<"the word you entered is:"<<arr<<'\n';
        cout<<"the length of the word you entered is:"<<strlen(arr)<<'\n';
}
void array2(){
        char arr1[50];
        cout<<"enter the sentace to be dispalyed:";
        cin.getline(arr1,50,'*');
        cout<<"the word you entered is:"<<arr1<<'\n';
        cout<<"the length of the word you entered is:"<<strlen(arr1)<<'\n';
}
int main(){
    array2();
    array1();
    return 0;
}