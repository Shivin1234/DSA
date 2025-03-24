// #include <iostream>
// using namespace std;
// int main()
// {
//     int i=1;
//     do{
//         cout<<i<<" ";
//         i++;
//         }
//     while(i<=5);
//     cout<<endl;
//     return 0;
// }


// #include <iostream>
// using namespace std;
// int main()
// {
//     int i=1;
//     while(i<=10){
//         if(i==3){
//             break;
//         }
//         cout<<i<<"\n";
//         i++;
//     }
//     cout<<"out of loop now";
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
   for(int i=1;i<=12;i++){
    if(i==3){
        continue;
    }
    cout<<i<<" ";
   }
    return 0;
}


