#include <iostream>
#include <vector>
using namespace std;

int main()
{
   vector<int> v1;
   for(int i=0;i<5;i++){
    v1.push_back(i);
   }
   cout<<v1.size()<<endl;
   cout<<v1.capacity()<<endl;
    return 0;
}