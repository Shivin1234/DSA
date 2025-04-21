#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int LIS(vector<int> arr){
    unordered_set<int> s(arr.begin(),arr.end());  //this is same as below as set only store unique values.

    /*for(int el : arr){
        s.insert(el);
    }*/
   vector<int> arr2(s.begin(),s.end());   //this is also same as above code
   sort(arr2.begin(),arr2.end());

   int n=arr.size();
   int m=arr2.size();
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));

   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1]==arr2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                int ans1=dp[i][j-1];
                int ans2=dp[i-1][j];
                dp[i][j]=max(ans1,ans2);
            }
        }
   }
   return dp[n][m];
}
int main(){
    vector<int> arr={50,3,30,7,40,80};
    cout<<LIS(arr);
    return 0;
}