#include<iostream>
#include<vector>
using namespace std;

class Disjoint{
    public:
        int n;
        vector<int> par;
        vector<int> rank;

        Disjoint(int n){
            this->n=n;

            for(int i=0;i<n;i++){
                par.push_back(i);
                rank.push_back(0);
            }
        }
        int find(int x){
            if(par[x]==x){
                return x;
            }
            return find(par[x]);
        }
        void unionbyrank(int a,int b){
            int parA=find(a);
            int parB=find(b);
            
            if(rank[parA]==rank[parB]){
                par[parB]=parA;
                rank[parA]++;

            }else if(rank[parA] > rank[parB]){
                par[parB]=parA;
            }else{
                par[parA]=parB;
            }
        }
};
int main(){
    Disjoint dj(6);
    dj.unionbyrank(0,2);
    cout<<dj.find(2)<<endl;
    dj.unionbyrank(1,3);
    dj.unionbyrank(2,5);
    dj.unionbyrank(0,3);
    cout<<dj.find(2)<<endl;
    dj.unionbyrank(0,4);

    return 0;
}
