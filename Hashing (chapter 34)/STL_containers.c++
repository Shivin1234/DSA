#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){
    unordered_map<string,int> m;                 //unordered map

    m["CHINA"]=150;
    m["INDIA"]=150;
    m["US"]=50;
    m["NEPAL"]=10;

    for(pair<string,int> country:m){
        cout<<country.first<<","<<country.second<<endl;
    }
    if(m.count("INDIA")){
        cout<<"exists"<<endl;
    }else{
        cout<<"does not exist"<<endl;
    }
    if(m.count("CANADA")){
        cout<<"exists"<<endl;
    }else{
        cout<<"does not exist"<<endl;
    }
    m.erase("NEPAL");
    for(pair<string,int> country:m){
        cout<<country.first<<","<<country.second<<endl;
    }
//--------------------------------------------------------------------------------------//
    map<string,int> m1;                 // map

    m1["CHINA"]=150;
    m1["INDIA"]=150;
    m1["US"]=50;
    m1["NEPAL"]=10;

    for(pair<string,int> country:m1){
        cout<<country.first<<","<<country.second<<endl;
    }
    if(m1.count("INDIA")){
        cout<<"exists"<<endl;
    }else{
        cout<<"does not exist"<<endl;
    }
    if(m1.count("CANADA")){
        cout<<"exists"<<endl;
    }else{
        cout<<"does not exist"<<endl;
    }
    m1.erase("NEPAL");
    for(pair<string,int> country:m1){
        cout<<country.first<<","<<country.second<<endl;
    }
    return 0;
}

