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
    Graph(int V, bool isundir){
        this->V = V;
        l = new list<int>[V];
        this->isundir = isundir;
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
void pathhelper(int src,int dest,vector<bool> &vis,string &path){   //all paths for directed graph so wew need to first create a directed graph above
    if(src == dest){
        cout<<path<<dest<<endl;
        return;
    }
    vis[src]=true;
    path += to_string(src);
    list<int> neighbours=l[src];
    
    for(int v:neighbours){
        if(!vis[v]){
            pathhelper(v,dest,vis,path);
            }
        }
        path=path.substr(0,path.size()-1);
        vis[src]=false;
    }

    void allpaths(int src,int dest){
        vector<bool> vis(V,false);
        string path="";
        pathhelper(src,dest,vis,path);
    }
};
int main(){
    Graph graph(6,false); // Specify the number of vertices

    graph.addedge(0,3);
    graph.addedge(2,3);
    graph.addedge(3,1);
    graph.addedge(4,0);
    graph.addedge(4,1);
    graph.addedge(5,0);
    graph.addedge(5,2);

    graph.allpaths(5,1);
    return 0;
}