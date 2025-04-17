#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isundir;
public:
    Graph(int V,bool isundir=true){
        this->V=V;
        l=new list<int> [V];
        this->isundir=isundir;
    }
    void addedge(int u,int v){        //u------->v
        l[u].push_back(v);
        if(isundir){
        l[v].push_back(u);
    }
}
    void print(){
        for(int u=0;u<V;u++){       //0,1,2,3,4
            list<int> neighbours=l[u];
            cout<<u<<" : ";
            for(int v : neighbours){
            cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    void helper(int src,vector<bool> &vis,stack<int> &s){
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v]){
                helper(v,vis,s);
            }
        }
        s.push(src);
    }
    void topological(){
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                helper(i,vis,s);
            }
        }
        while(s.size()>0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};
int main(){
    Graph graph(6,false);
    graph.addedge(2,3);
    graph.addedge(3,1);

    graph.addedge(4,0);
    graph.addedge(4,1);
    
    graph.addedge(5,0);
    graph.addedge(5,2);

    graph.topological();
    return 0;
}