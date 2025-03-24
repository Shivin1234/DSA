// #include <iostream>
// using namespace std;

// int digsum(int n){
// int rev=0;
// while(n>0){
//     rev=rev+n%10;
//     n=n/10;
// }
//     return rev;
// }
// int main()
// {
//     int sum=digsum(154);
//     cout<<sum;
//     return 0;
// }

#include <iostream>
using namespace std;

int largenumber(int a,int b,int c){
    if(a>=b && a>=c){
        cout<<"largest number is:"<<a;
    }
    else if(b>=c){
        cout<<"largest number is:"<<b;
    }
    else{
        cout<<"largest number is:"<<c;
    }
}
int main()
{
int x,y,z;
cout<<"enter value of x:";
cin>>x;
cout<<"enter value of y:";
cin>>y;
cout<<"enter value of z:";
cin>>z;

largenumber(x,y,z);

    return 0;
}
