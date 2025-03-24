#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isvalid(string str){
    stack<char> s;

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            s.push(ch);
        }else{          //closing parenthesis
            if(s.empty()){
                return false;
            }
        
        int top=s.top();
        if((top=='(' && ch==')')||
           (top=='[' && ch==']')||
           (top=='{' && ch=='}')){
            s.pop();
        }else{
            return false;
        }
        }
    }
    if(s.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string str1="([}])";    //invalid string generate false
    string str2="([{}])";  //valid string generate true
    cout<<isvalid(str1)<<endl;
    cout<<isvalid(str2)<<endl;
    return 0;

}