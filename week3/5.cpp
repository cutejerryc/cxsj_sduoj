#include<bits/stdc++.h>
using namespace std;
int n,k;
int num;
void recursion(vector<bool>judge_row,vector<bool>judge_col,vector<pair<int,int>>position_can,int k){
    while(position_can.size()>=k){
        k--;
        if(k==0){
            num++;
            k++;
            position_can.erase(position_can.begin(),position_can.begin()+1);
            continue;
        }
        int x=position_can.begin()->first;
        int y=position_can.begin()->second;
        judge_row[x]=false;
        judge_col[y]=false;
        position_can.erase(position_can.begin(),position_can.begin()+1);
        vector<pair<int,int>>re;
        for(int i=0;i<position_can.size();i++){
            if(judge_row[position_can[i].first]&&judge_col[position_can[i].second]){
                re.push_back(position_can[i]);
            }
        }
        recursion(judge_row,judge_col,re,k);
        k++;
        judge_row[x]=true;
        judge_col[y]=true;
    }
}
void deal(){
    vector<bool>judge_row(n+1,true);
    vector<bool>judge_col(n+1,true);
    vector<pair<int,int>>position_can;
    char c;
    for(int i=0;i<n;i++){
        for(int u=0;u<n;u++){
           cin>>c;
           if(c=='#'){
            position_can.push_back(make_pair(i,u));
           } 
        }
    }
    recursion(judge_row,judge_col,position_can,k);
}
int main(){
    while(1){
        num=0;
        cin>>n>>k;
        if(n==k&&k==-1){
            break;
        }
        deal();
        cout<<num<<endl;
    }
}