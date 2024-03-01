#include<bits/stdc++.h>
using namespace std;
set<string>s;
void op1(string str){
    if(s.find(str)!=s.end()){
        cout<<"found"<<endl;
    }else{
        cout<<"write"<<endl;
        s.insert(str);
    }
}
void op2(string str){
    if(s.find(str)!=s.end()){
        cout<<"erased"<<endl;
        s.erase(str);
    }else{
        cout<<"not found"<<endl;
    }
}
void op3(){
    for(const auto&e:s){
        cout<<e<<' ';
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    char op;
    string opstr;
    for(int i=0;i<n;i++){
        cin>>op;
        switch (op)
        {
        case '1':
            cin>>opstr;
            op1(opstr);
            break;
        case '2':
            cin>>opstr;
            op2(opstr);
            break;
        case '3':
            op3();
            break;
        default:
            break;
        }
    }
}