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
    void calcindegree(vector<int> &indeg){
        for(int u=0;u<V;u++){
            list<int> neighbours=l[u];
            for(int v:neighbours){
                indeg[v]++;
            }
        }
    }
    void toposort(){                                //kahn's algorithm is topological sorting by bfs
        vector<int> indeg(V,0);
        calcindegree(indeg);
        queue<int> q;
        //now finding 0 indegree nodes->because they are starting point
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";
            list<int> neighbours=l[curr];
            for(int v:neighbours){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
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

    graph.toposort();
    return 0;
}