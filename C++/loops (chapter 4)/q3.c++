// #include <iostream>
// using namespace std;
// int main()
// {
//     int n=10829;
//     int sum=0;
//     while(n>0){
//         int lastdig=n%10;
//         cout<<lastdig<<" ";
//         n=n/10;
        
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n=10829;
    int result=0;
    while(n>0){
        int lastdig=n%10;
        result=result*10+lastdig;
        n=n/10;
     }
     cout<<"reverse of the number is = "<<result;
    return 0;
}
