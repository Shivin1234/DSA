#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
  return  p1.second > p2.second;
}

int maxprofit(vector<pair<int,int>> job){
    int n=job.size();
    sort(job.begin(),job.end(),compare);
    int profit=job[0].second;
    int safedeadline=job[0].first+1;

    for(int i=1;i<n;i++){
        if(job[i].first>=safedeadline){
            profit+=job[i].second;
            safedeadline++;
        }
    }
    cout<<"maximum profit : "<<profit<<endl;
    return profit;
}
int main(){
    int n=4;
    vector<pair<int,int>> job(n,make_pair(0,0));
    job[0]=make_pair(4,20);
    job[1]=make_pair(1,10);
    job[2]=make_pair(1,40);
    job[3]=make_pair(1,30);
    maxprofit(job);
    return 0;
}