#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;    //max heap
    pq.push(5);
    pq.push(10);
    pq.push(3);
    while(!pq.empty()){
    cout<<"top : "<<pq.top()<<endl;
    pq.pop();
    }
    cout<<endl;
    
   priority_queue<int,vector<int>,greater<int>> pq1;    //min heap
    pq1.push(5);
    pq1.push(10);
    pq1.push(3);
    while(!pq1.empty()){
    cout<<"top : "<<pq1.top()<<endl;
    pq1.pop();
    } 
    return 0;
}