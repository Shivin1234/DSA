#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> * l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int> [V];
    }
    void addedge(int u,int v){        //u-------v
        l[u].push_back(v);
        l[v].push_back(u);
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
//--------------------------------------------------------------------------------------------------------------------//
    void disconnectdfshelper(int u,vector<bool> &vis){       //dfs for disconnected graph
        cout<<u<<" ";
        vis[u]=true;
        list<int> neighbours=l[u];
        for(int v:neighbours){
            if(!vis[v]){
                disconnectdfshelper(v,vis);
            }
        }
    }
    void disconnectdfs(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                disconnectdfshelper(i,vis);   //starting point = i
                cout<<endl;
            }
        }
    }
//------------------------------------------------------------------------------------------------------------------//
    void disconnectbfshelper(int st,vector<bool> &vis){
        queue<int> q;
         q.push(st);
        vis[st]=true;        
        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            list<int> neighbours=l[u];
            for(int v : neighbours){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    void disconnectbfs(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                disconnectbfshelper(i,vis);
                cout<<endl;
            }
        }
    }
};
int main(){
    Graph graph(10); // Specify the number of vertices

    graph.addedge(0,2);
    graph.addedge(2,5);
    graph.addedge(1,6);
    graph.addedge(6,4);
    graph.addedge(4,9);
    graph.addedge(4,3);
    graph.addedge(3,8);
    graph.addedge(3,7);
    graph.disconnectdfs();
    graph.disconnectbfs();
    return 0;
}