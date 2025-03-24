#include<iostream>
#include<string>
#include<vector>
using namespace std;
void substring(string str,string sub){
    if(str.size()==0){
        cout<<sub<<"\n";
        return;
    }
    char ch=str[0];
    substring(str.substr(1,str.size()-1),sub+ch); //yes
    substring(str.substr(1,str.size()-1),sub); //no
}
int main(){
    string str="abc";
    string sub="";
    substring(str,sub);
    return 0;
}