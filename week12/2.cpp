#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n;
    vector<int>a;
    Deal(){
        cin>>n;
        int g;
        a=vector<int>(1e6,0);
        for(int i=0;i<n;i++){
            cin>>g;
            a[g]++;
        }
    }
    void solve(){
        vector<long long int>ans(1e6+1,0);
        ans[0]=0;
        ans[1]=a[1]*1;
        for(int i=2;i<=1e6;i++){
            ans[i]+=std::max(ans[i-1],ans[i-2]+a[i]*i);
        }
        cout<<ans[1e6]<<endl;
    }
};
int main(){
    Deal().solve();
}