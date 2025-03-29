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
    bool bipertite(){
        queue<int> q;
        vector<int> color(V,-1);
        q.push(0);
        color[0]=0;

        while(q.size()>0){
            int curr=q.front();
            q.pop();
            list<int> neighbours=l[curr];
            for(int v:neighbours){
                if(color[v]==-1){
                    color[v] = !color[curr];
                    q.push(v);
                }else if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
            return true;
        }
    };
int main(){
    Graph graph(4);

    graph.addedge(0,1);
    graph.addedge(0,2);
    graph.addedge(1,3);
    graph.addedge(2,3);

    cout<<graph.bipertite();
    return 0;
}