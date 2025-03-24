// #include <iostream>
// using namespace std;
// int main()
// {
//     int n=12345;
//     int sum=0;
//     while(n>0){
//         int lastdig=n%10;
//         sum=sum+lastdig;
//         n=n/10;
//     }
//     cout<<"sum is = "<<sum<<"\n";
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n=11111;
    int sum=0;
        while(n>0){
            int lastdig=n%10;
            if(n%2!=0){
            sum+=lastdig;
            }
            n=n/10;
        }
        cout<<"sum is = "<<sum<<"\n";

    
    return 0;
}
