#include<bits/stdc++.h>
using namespace std;
set<string>s;//利用set可以自动按照字典序排列
void op1(string str){//查找单词的函数
    if(s.find(str)!=s.end()){
        cout<<"found"<<endl;
    }else{
        cout<<"write"<<endl;
        s.insert(str);
    }
}
void op2(string str){//删除单词的操作
    if(s.find(str)!=s.end()){
        cout<<"erased"<<endl;
        s.erase(str);
    }else{
        cout<<"not found"<<endl;
    }
}
void op3(){//按字典序通读笔记本
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
        case '1'://查找
            cin>>opstr;
            op1(opstr);
            break;
        case '2'://删除
            cin>>opstr;
            op2(opstr);
            break;
        case '3'://通读
            op3();
            break;
        default:
            break;
        }
    }
}