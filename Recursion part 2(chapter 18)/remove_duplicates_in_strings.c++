#include <iostream>
#include <string>
using namespace std;
void removeduplicate(string str,string ans,int i,int map[26]){
    if(i==str.size()){
        cout<<"ans:"<<ans<<endl;
        return;
    }
    char ch=str[i];
    int mapidx=(int)(ch-'a');
    if(map[mapidx]){
        removeduplicate(str,ans,i+1,map);
    }
    else{
        map[mapidx]=true;
        removeduplicate(str,ans+ch,i+1,map);
    }
}
int main()
{
    string str="shivin bassi";
    string ans="";
    int map[26]={false};
    removeduplicate(str,ans,0,map);
    return 0;
}
