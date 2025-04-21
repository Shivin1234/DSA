#include<iostream>
#include<vector>
using namespace std;

int knapsackrec(vector<int> val,vector<int> wt,int W,int n){
    if(n==0 || W==0){
        return 0;
    }
    int itemwt=wt[n-1];
    int itemval=val[n-1];

    if(itemwt<=W){
        //include
        int ans1=knapsackrec(val,wt,W-itemwt,n-1)+itemval;

        //exclude
        int ans2=knapsackrec(val,wt,W,n-1);

        return max(ans1,ans2);
    }else{
        //exclude
        return knapsackrec(val,wt,W,n-1);
    }
}
//--------------------------------------memoization---------------------------------------------------------------------//
int knapsackmemo(vector<int> val,vector<int> wt,int W,int n,vector<vector<int>> &dp){
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    int itemwt=wt[n-1];
    int itemval=val[n-1];

    if(itemwt<=W){
        //include
        int ans1=knapsackmemo(val,wt,W-itemwt,n-1,dp)+itemval;

        //exclude
        int ans2=knapsackmemo(val,wt,W,n-1,dp);

        dp[n][W]=max(ans1,ans2);
    }else{
        //exclude
        dp[n][W]=knapsackmemo(val,wt,W,n-1,dp);
    }
    return dp[n][W];
}
//--------------------------------------tabulation---------------------------------------------------------------------//
int knapsacktab(vector<int> val,vector<int> wt,int W,int n){
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            int itemwt=wt[i-1];
            int itemval=val[i-1];

            if(itemwt<=j){
                dp[i][j]=max(itemval+dp[i-1][j-itemwt],dp[i-1][j]);
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
    cout<<knapsacktab(val,wt,W,n);
    return 0;
}