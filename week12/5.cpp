#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n,m;
    vector<int>a,b;
    vector<vector<int>>dp;
    Deal(){
        cin>>n>>m;
        int g;
        for(int i=0;i<n;i++){
            cin>>g;
            a.push_back(g);
        }
        for(int i=0;i<m;i++){
            cin>>g;
            b.push_back(g);
        }
        dp=vector<vector<int>>(n+1,vector<int>(m+1,0));
    }
    void solve(){
        for(int i=1;i<=n;i++){
            for(int u=1;u<=m;u++){
                if(a[i-1]==b[u-1]){
                    dp[i][u]=dp[i-1][u-1]+1;
                }else{
                    dp[i][u]=max(dp[i-1][u],dp[i][u-1]);
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
};
int main(){
    Deal().solve();
}