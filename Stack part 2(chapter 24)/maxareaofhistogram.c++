#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int maxareahistogram(vector<int> height){
    int n=height.size();
    vector<int> nsl(n);      //nextsmaller on left
    vector<int> nsr(n);      //nextsmaller on right
    stack<int> s;

    //next smaller left
    nsl[0]=-1;
    s.push(0);
    for(int i=1;i<height.size();i++){
        int curr=height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i]=-1;
        }else{
            nsl[i]=s.top();
        }
        s.push(i);
    }
        while(!s.empty()){        //to empty the stack for next smaller right elements
            s.pop();
        }

    //next smaller right
    
    s.push(n-1);
    nsr[n-1]=n;        //n-1 is the last index of the stack and we put n because we cant put -1 there

    for(int i=n-2;i>=0;i--){
        int curr=height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=n;       //the ans should be -1 but we cant put -1 in the formula (r-l-1) to calculate width.
        }else{
            nsr[i]=s.top();
        }
        s.push(i);
    }

    int maxarea=0;
    for(int i=0;i<height.size();i++){
        int ht=height[i];
        int width=nsr[i]-nsl[i]-1;
        int area=ht*width;
        maxarea=max(area,maxarea);
    }
    return maxarea;
    cout<<endl;
}
int main(){
    vector<int> height={2,1,5,6,2,3};
    cout<<maxareahistogram(height);
    return 0;
}