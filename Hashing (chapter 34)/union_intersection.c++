#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void printunion(vector<int> arr1,vector<int> arr2){
    unordered_set<int> s;

    for(int i:arr1){
        s.insert(i);
    }
    for(int i:arr2){
        s.insert(i);
    }
    for(int i:s){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr1={7,3,9};
    vector<int> arr2={6,3,9,2,9,4};
    cout<<"union is:";
    printunion(arr1,arr2);
    return 0;
}