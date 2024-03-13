#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<priority_queue<int,vector<int>,greater<int>>>a(n+1,priority_queue<int,vector<int>,greater<int>>());
    int p,q;
    for(int i=0;i<m;i++){
        cin>>p>>q;
        a[q].push(p);
    }
    for(int i=1;i<a.size();i++){
        while(a[i].size()>0){
            cout<<a[i].top()<<' ';
            a[i].pop();
        }
        cout<<endl;
    }
}