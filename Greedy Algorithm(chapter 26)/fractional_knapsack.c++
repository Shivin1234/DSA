#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double,int> p1,pair<double,int> p2){
    return p1.first > p2.first;          //in pair(ratio,idx) we want to sort acc to ratio which is 1st value. 
}
int fractionalknapsack(vector<int> val,vector<int> wt,int W){
    int n=val.size();
    vector<pair<double,int>> ratio(n,make_pair(0.0,0));       //pair(ratio,idx)--->(double,int)
    
    for(int i=0;i<n;i++){
            double r=val[i]/(double)wt[i];
            ratio[i]=make_pair(r,i);
    }
    sort(ratio.begin(),ratio.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=ratio[i].second;
        if(wt[idx]<=W){
            ans+=val[idx];
            W-=wt[idx];
        }else{
            ans+=ratio[i].first*W;
            W=0;
            break;
        }
    }
        cout<<"maximum value:"<<ans<<endl;
        return ans;
}

int main(){
    vector<int> val={60,100,120};
    vector<int> wt={10,20,30};
    int W=50;
    fractionalknapsack(val,wt,W);
    return 0;
}