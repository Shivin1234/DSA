#include <iostream>
#include <vector>
#include <string>
using namespace std;

int editdist(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

     // Base cases
     for (int i = 0; i <= n; ++i) dp[i][0] = i; // delete all characters
     for (int j = 0; j <= m; ++j) dp[0][j] = j; // insert all characters

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                int ans1=1+dp[i][j-1];    //insert
                int ans2=1+dp[i-1][j];    //delete
                int ans3=1+dp[i-1][j-1];  //replace
                dp[i][j]=min(ans1,min(ans2,ans3));
            }
        }
    }
    return dp[n][m];
}
int main(){
    string str1="horse";
    string str2="ros";
    cout<<editdist(str1,str2);
    return 0;
}