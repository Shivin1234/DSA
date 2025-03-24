#include<iostream>
#include<string>
#include<vector>
using namespace std;
int gridways(int r,int c,int n,int m,string ans){
    if(r==n-1 && c==m-1){   //base case for destination
        cout<<ans<<"\n";
        return 1;
    }
    if(r>=n || c>=m){   //base case for destination
        return 0;
    }

    int val1=gridways(r,c+1,n,m,ans+'R'); //right way
    int val2=gridways(r+1,c,n,m,ans+'D'); //down way
    return val1+val2;
}
int main(){
    int n=3;
    int m=3; //3x3 grid
    string ans="";
    cout<<gridways(0,0,n,m,ans);
    return 0;
}