#include <iostream>
#include <vector>
using namespace std;
int FO(vector<int> arr,int i,int target){
    if(i==arr.size()){
        return -1;
    }

int idxfound=FO(arr,i+1,target);
    if (idxfound==-1){
        if(arr[i]==target){
            return i;            
        }
    }
    return idxfound;
}
int main()
{
  vector<int> arr1={1,2,4,3,3}; 
  vector<int> arr2={2,5,4,1,1}; 
  cout<<FO(arr1,0,3)<<endl;
  cout<<FO(arr2,0,8)<<endl;
    return 0;
}