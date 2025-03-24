#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack{
    vector<int> vec;
    public:
        void push(T val){
            vec.push_back(val);
        }
        void pop(){
            if(isempty()){
                cout<<"stack is empty\n";
                return;
            }
            vec.pop_back();
        }
        T top(){
            if(isempty()){
                cout<<"stack is empty\n";
                return -1;
            }
            int lastidx=vec.size()-1;
            return vec[lastidx];
        }
        bool isempty(){
            return vec.size()==0;
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