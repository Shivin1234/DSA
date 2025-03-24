#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap{
    vector<int> vec;
public:
    void push(int val){        //max heap
        vec.push_back(val);
        int x=vec.size()-1;
        int par=(x-1)/2;

        while(par>=0 && vec[x] > vec[par]){     //for min heap vec[x] < vec[par]
            swap(vec[x],vec[par]);
            x=par;
            par=(x-1)/2;
        }
    }
    void heapify(int i){           //i=parent idx
        if(i >=vec.size()){
            return;
        }
        int l=2*i+1;
        int r=2*i+2;

        int maxidx=i;
        if(l < vec.size() && vec[l] > vec[maxidx]){
            maxidx=l;
        }
        if(r < vec.size() && vec[r] > vec[maxidx]){
            maxidx=r;
        }
        swap(vec[i],vec[maxidx]);
        if(maxidx != i){
            heapify(maxidx);
        }
    }
    void pop(){
        swap(vec[0],vec[vec.size()-1]);

        vec.pop_back();

        heapify(0);
    }
    int top(){
        return vec[0];
    }
    bool empty(){
        return vec.size()==0;
    }
};
int main(){
    Heap heap;
    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);
    while(!heap.empty()){
    cout<<"top : "<<heap.top()<<endl;
     heap.pop();
    }
        return 0;
}