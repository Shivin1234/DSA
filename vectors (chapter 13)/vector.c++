#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector <int> v1(10,-1);
    cout<<v1.size()<<endl;

    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    
    vector <int> v2={1,2,3,4};
    cout<<"size is:"<<v2.size()<<endl;
    cout<<"capacity is:"<<v2.capacity()<<endl;
    
    v2.push_back(5);
    cout<<"size is:"<<v2.size()<<endl;
    cout<<"capacity is:"<<v2.capacity()<<endl;//when we add new element to vector whose capacity is full then its capacity becomes double.In above case we added 5 to vector with capacity of 4 elements so a new vector of capacity 8 is created to save item 5.

    v2.pop_back();
    cout<<"size is:"<<v2.size()<<endl;
    cout<<"capacity is:"<<v2.capacity()<<endl;
    return 0;
}
