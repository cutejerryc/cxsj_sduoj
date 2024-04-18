#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n;
    vector<pair<int,int>>h,w;
    int max_h,max_w,max_t;
    int d[1000002]={0};
    Deal(){
        cin>>n;
        int a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            h.push_back(make_pair(a,b));
        }
        for(int i=0;i<n;i++){
            cin>>a>>b;
            w.push_back(make_pair(a,b));
        }
        max_h=h[h.size()-1].second;
        max_w=w[w.size()-1].second;
        max_t=max(max_h,max_w);
    }
    void solve(){
        for(int i=0;i<h.size();i++){
            d[h[i].first]+=1;
            d[h[i].second]-=1;
        }
        for(int i=0;i<w.size();i++){
            d[w[i].first]+=1;
            d[w[i].second]-=1;
        }
        int t=0;
        for(int i=1;i<=max_t;i++){
            t+=d[i];
            d[i]=t;
        }
        int time=0;
        for(int i=1;i<=max_t;i++){
            time+=(d[i]==2);
        }
        cout<<time<<endl;
    }
};
int main(){
    Deal().solve();
}