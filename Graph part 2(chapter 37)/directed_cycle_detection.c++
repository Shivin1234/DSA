#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
    bool dircyclehelper(int src,vector<bool> vis,vector<bool> recpath){
        vis[src]=true;
        recpath[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v]){
                if(dircyclehelper(v,vis,recpath)){
                    return true;
                }
            }else{
                if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src]=false;
        return false;
    }
    bool iscycledir(){
        vector<bool> vis(V,false);
        vector<bool> recpath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dircyclehelper(i,vis,recpath)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){

    Graph graph(4,false); // Specify the number of vertices
    graph.addedge(1,0);
    graph.addedge(0,2);
    graph.addedge(2,3);
    graph.addedge(3,0);
    cout<<graph.iscycledir();
    return 0;
}