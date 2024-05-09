#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    long long int r_to_g,y_to_g;
     long long int r_time,g_time,y_time;
    vector<pair<long long int,long long int>>a;
    Deal(){
       
        cin>>r_time>>y_time>>g_time;
        r_to_g=r_time;
        y_to_g=y_time+r_time;
        long long int n;
        cin>>n;
        long long int k,t;
        for(long long int i=0;i<n;i++){
            cin>>k>>t;
            a.push_back(make_pair(k,t));
        }
    }
    void solve(){
        long long int sum=0;
        for(auto&d:a){
            if(d.first==0){
                sum+=d.second;
            }else if(d.first==1){
                sum+=d.second;
            }else if(d.first==2){
                sum+=d.second+r_time;
            }else{

            }
        }
        cout<<sum<<endl;
    }
};
int main(){
    Deal().solve();
}