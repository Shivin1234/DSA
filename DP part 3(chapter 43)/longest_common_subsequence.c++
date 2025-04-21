#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsrec(string str1,string str2){
    if(str1.size()==0 || str2.size()==0){
        return 0;
    }
    int n=str1.size();
    int m=str2.size();

    if(str1[n-1]==str2[m-1]){
        return 1+lcsrec(str1.substr(0,n-1),str2.substr(0,m-1));
    }else{
        int ans1=lcsrec(str1.substr(0,n-1),str2);
        int ans2=lcsrec(str1,str2.substr(0,m-1));
        return max(ans1,ans2);
    }
}
//-------------------------------------------------memoization--------------------------------------------------------------------//
int lcsmemo(string str1,string str2, vector<vector<int>> dp){
    if(str1.size()==0 || str2.size()==0){
        return 0;
    }
    int n=str1.size();
    int m=str2.size();
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(str1[n-1]==str2[m-1]){
        dp[n][m]=1+lcsmemo(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }else{
        int ans1=lcsmemo(str1.substr(0,n-1),str2,dp);
        int ans2=lcsmemo(str1,str2.substr(0,m-1),dp);
        dp[n][m]=max(ans1,ans2);
    }
    return dp[n][m];
}
//--------------------------------------------------tabulation----------------------------------------------------------------------//
int lcstab(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string str1="abcdge";
    string str2="abedg";
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<<lcstab(str1,str2);
    return 0;
}