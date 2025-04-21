#include<iostream>
#include<vector>
using namespace std;

int unboundknapsack(vector<int> val,vector<int> wt,int W,int n){
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            int itemwt=wt[i-1];
            int itemval=val[i-1];

            if(itemwt<=j){
                dp[i][j]=max(itemval+dp[i][j-itemwt],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    vector<int> val={15,14,10,45,30};
    vector<int> wt={2,5,1,3,4};
    int W=7;
    int n=5;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout<<unboundknapsack(val,wt,W,n);
    return 0;
}