#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(0));
    int p,q;
    for(int i=0;i<m;i++){
        cin>>p>>q;
        a[q].push_back(p);
    }
    for(int i=1;i<a.size();i++){
        for(int u=0;u<a[i].size();u++){
            sort(a[i].begin(),a[i].end());
            cout<<a[i][u]<<' ';
        }
        cout<<endl;
    }
}