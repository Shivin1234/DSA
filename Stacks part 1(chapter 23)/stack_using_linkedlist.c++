#include<iostream>
#include<list>
using namespace std;
template<class T>
class Stack{
list<T> ll;
public:
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    T top(){
        return ll.front();
    }
    bool isempty(){
        return ll.size()==0;
    }
};
int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.isempty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}