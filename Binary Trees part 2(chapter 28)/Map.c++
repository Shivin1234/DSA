#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int,string> m;

    m[101]="rahul";
    m[110]="neha";
    m[131]="rahul";
    m[101]="rajat";    //key 101 got overwrite.

    cout<<m[101]<<endl;
    cout<<m[131]<<endl;
    cout<<m[110]<<endl;
    cout<<m[101]<<endl;

    cout<<m.count(101)<<endl;    //count is used to show weather a key exist or not if exist it give 1 and if not then it give 0;
    cout<<m.count(100)<<endl;

    for(auto it:m){
        cout<<"key = "<<it.first<<","<<it.second<<endl;
    }
    return 0;
}