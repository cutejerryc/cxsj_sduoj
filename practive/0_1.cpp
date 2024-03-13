#include<bits/stdc++.h>
using namespace std;
    string s="01";
    string sub_s;
    int n;
    int get_nums(){
        int sum=0;
        int i=0;
        int p=0;
        while(i!=s.size()){
            p=s.find(sub_s,i);
            if(p!=-1){
                sum++;
            }else{
                break;
            }
            i=p+1;
        }
        return sum;
    }
    string get_deal_string(string s){
        for(int i=0;i<s.size();i++){
            s[i]=s[i]=='1'?'0':'1';
        }
        return s;
    }
    void generate_string(){
        s=s;
        while(s.size()<=n){
            s=s+get_deal_string(s);
        }
        s=s.substr(0,n);
    }
int main(){
        cin>>n;
        cin>>sub_s;
        generate_string();
        cout<<get_nums();
}