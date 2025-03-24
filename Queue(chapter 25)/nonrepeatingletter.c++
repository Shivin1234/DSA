#include<iostream>
#include<string>
#include<queue>
using namespace std;

void firstnonrepeat(string str){
    queue<char> q;
    int freq[26]={0};

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        q.push(ch); 
        freq[ch-'a']++;

        while(!q.empty() && freq[q.front()-'a']>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1\n";
        }else{
            cout<<q.front()<<endl;
        }
    }
}

int main(){
    string str="aabccxb";
    firstnonrepeat(str);
    return 0;
}