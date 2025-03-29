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
    bool undircyclehelper(int src,int par,vector<bool> &vis){
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v]){
                if(undircyclehelper(v,src,vis)){
                    return true;
                }
            }else{
                if(v!=par){              //cycle condition
                    return true;
                }
            }
        }
        return false;
    }
    bool iscycleundir(){
        vector<bool> vis(V,false);
        return undircyclehelper(0,-1,vis);
    }
};

int main(){
    int V=5;
    Graph graph(V); // Specify the number of vertices

    graph.addedge(0,1);
    graph.addedge(0,2);
    graph.addedge(0,3);
    graph.addedge(1,2);
    graph.addedge(3,4);
    cout<<graph.iscycleundir()<<endl;
    return 0;
}