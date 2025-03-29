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
    bool haspath(int src,int dest,vector<bool> &vis){
        if(src==dest){
            return true;
        }
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v]){
               if(haspath(v,dest,vis)){
                return true;
               }
            }
        }
        return false;
    }
};
int main(){
    Graph graph(7); // Specify the number of vertices

    graph.addedge(0,1);
    graph.addedge(0,2);
    graph.addedge(1,3);
    graph.addedge(2,4);
    graph.addedge(3,4);
    graph.addedge(3,5);
    graph.addedge(4,5);
    graph.addedge(5,6);
    vector<bool> vis(7,false);
    cout<<graph.haspath(0,5,vis);
    return 0; 
}