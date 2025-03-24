// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     while(true){
//         cout<<"enter a number:";
//         cin>>n;
//         cout<<"number you entered = "<<n<<"\n";
//         if(n%10==0){
//             break;
//         }
//     }    
//     return 0;
// }


#include <iostream>
using namespace std;
int main()
{
    int n;
    while(true){
        cout<<"enter a number:";
        cin>>n;
        if(n%10==0){
            continue;
        }
        cout<<"number you entered = "<<n<<"\n";
    }    
    return 0;
}