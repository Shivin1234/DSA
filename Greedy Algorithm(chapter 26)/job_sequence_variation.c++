#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Job{
    public:
        int idx;
        int deadline;
        int profit;

        Job(int idx,int deadline,int profit){
            this->idx=idx;
            this->deadline=deadline;
            this->profit=profit;
        }
};

int maxprofit(vector<pair<int,int>> pairs){
    int n=pairs.size();
    vector<Job> jobs;

    for(int i=0;i<n;i++){
        jobs.emplace_back(i,pairs[i].first,pairs[i].second);         //idx,deadline,profit
    }
    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b){                //[] is capture list,() is lambda function
        return a.profit > b.profit;
    }); //descending order on the bases of profit.      
    
    cout<<"selecting job"<<jobs[0].idx<<endl;
    int profit=jobs[0].profit;
    int safedeadline=jobs[0].deadline+1;

    for(int i=1;i<n;i++){
        if(jobs[i].deadline>=safedeadline){
            cout<<"selecting job"<<jobs[i].idx<<endl;
            profit+=jobs[i].profit;
            safedeadline++;
        }
    }
    cout<<"maximum profit :"<<profit<<endl;
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