#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int> d;
    public:
        void push(int data){
            d.push_back(data);
        }
        void pop(){
            d.pop_back();
        }
        int top(){
            return d.back();
        }
        bool empty(){
            return d.empty();
        }
};
int main(){
    Stack s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    for(int i=1;i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}