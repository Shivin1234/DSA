#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool duplicate(string str){
    stack<char> s;

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch!=')'){       //non closing elements like(,a,b,c,d,+
            s.push(ch);
        }else{            //closing
            if(s.top()=='('){
                return true;   //duplicate
            }
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main(){
    string str1="((a+b))";    //invalid return false
    string str2="((a+b)+(c+d))";    //valid return true
   cout<<duplicate(str1)<<endl;;
   cout<<duplicate(str2)<<endl;
    return 0;
}