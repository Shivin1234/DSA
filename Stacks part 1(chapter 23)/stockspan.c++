#include<iostream>
#include<vector>
#include<stack>
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
        void stockspanproblem(vector<int> stock,vector<int> span){
            stack<int> s;
            s.push(0);    
            span[0]=1;

            for(int i=1;i<stock.size();i++){
                int currprice=stock[i];
                while(!s.empty() && currprice>=stock[s.top()]){
                    s.pop();
                }
                if(s.empty()){
                    span[i]=i+1;
                }else{
                    int prevhigh=s.top();
                    span[i]=i-prevhigh;
                }
            }
            for(int i=0;i<span.size();i++){
                cout<<span[i]<<" ";
                }
            cout<<endl;
            }
int main(){
    vector<int> stock={100,80,60,70,60,85,100};
    vector<int> span={0,0,0,0,0,0,0};
    stockspanproblem(stock,span);
    return 0;
    }
