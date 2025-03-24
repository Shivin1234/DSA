#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str="my name is shivin bassi";
    cout<<str.length()<<endl;
    cout<<str.at(3)<<endl;    //used to find value at the index
    cout<<str.substr(1,3)<<endl;    //used to find substring 
    cout<<str.find("bassi")<<endl;    //used to find word in a string
    
    return 0;
}
