#include<bits/stdc++.h>
using namespace std;
void func(){
        vector<int> a(26,0);
        string s;
        int caps_sum=0;
        cin>>s;
        char c=' ';
        bool if_right=true;
        if(s.size()==0){
            if_right=false;
        }
        for(auto it=s.begin();it!=s.end();it++){
            if(*it<=90){
                caps_sum++;
                a[*it-65]=1;
            }else{
                a[*it-97]=1;
            }
            if(it==s.begin()){
                c=*it;
                continue;
            }
            if(*it==c){
                if_right=false;
            }
            if(c==*it){
                if_right=false;
                break;
            }else{
                c=*it;
            }
        }
        for(auto it=a.begin();it!=a.end();it++){
            if(*it==0){
                if_right=false;
            }
        }
        if(caps_sum==s.size()||caps_sum==0){
            if_right=false;
        }
        if(if_right){
            cout<<"no"<<endl;
        }else{
            cout<<"yes"<<endl;
        }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        func();
    }
    return 0;
}