#include<iostream>
#include<stack>
using namespace std;
void pushatbottom(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp=s.top();
    s.pop();
    pushatbottom(s,val);
    s.push(temp);
}
int main(){
     stack<int> s; 
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    pushatbottom(s,6);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}