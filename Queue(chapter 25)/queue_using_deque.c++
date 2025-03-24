#include<iostream>
#include<deque>
using namespace std;

class Queue{
    deque<int> d;
    public:
        void push(int data){
            d.push_back(data); 
        }
        void pop(){
            d.pop_front(); 
        }
        int front(){
            return d.front(); 
        }
        bool empty(){
            return d.empty();
        }

};
int main(){
    Queue q;
    for(int i=1;i<=5;i++){
        q.push(i);
        
    }
    for(int i=1;i<=5;i++){
        cout<<q.front()<<" ";
        q.pop();
        cout<<endl;
    }
    return 0;
}