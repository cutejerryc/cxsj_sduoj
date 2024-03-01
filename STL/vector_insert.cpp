#include<bits/stdc++.h>
using namespace std;
void out(vector<int>&a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
int main(){
    vector<int>array(10,1);
    array.insert(array.begin(),1412);
    out(array);
    array.erase(array.begin());
    out(array);
    array.erase(array.begin(),array.begin()+array.size());
    out(array);
    set<string>st;
    st.insert("haha");
    unordered_map<string,int>um;
    um["wx"]=0621;
    um.at("wx")=1412;
    cout<<um["wx"];
    um["wx1"]=1412;
    um.erase("wx1");
    if(um.find("wx1")==um.end()){
        cout<<"delete wx1"<<endl;
    }
    stack<int>sk;
    sk.push(1);
}