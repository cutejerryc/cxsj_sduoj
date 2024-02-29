#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int get_val(int&u,vector<int>&a){
    int re=0;
    for(int i=0;i<a.size();i++){
        re+=pow((a[i]-u),2);
    }
    return re;
}
int main(){
    int n;
    int l=INT32_MAX,r=INT32_MIN;
    int min_val=INT32_MAX;
    vector<int>a;
    cin>>n;
    int g;
    for(int i=0;i<n;i++){
        cin>>g;
        if(g<l){
            l=g;
        }
        if(g>r){
            r=g;
        }
        a.push_back(g);
    }
    for(int i=l;i<=r;i++){
        int tmp=get_val(i,a);
        if(tmp<min_val){
            min_val=tmp;
        }
    }
    cout<<min_val;
    return 0;
}