#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
class Deal{
    public:
    int n,m,k;
    vector<bool>stairs;
    vector<int>stair_kinds;
    Deal(){
        cin>>n>>m>>k;
        stair_kinds=vector<int>(n+1,0);
        stairs=vector<bool>(n+1,true);
        int g;
        for(int i=0;i<m;i++){
            scanf("%d",&g);
            stairs[g]=false;
        }
        stair_kinds[0]=1;
    }
    long long int f(const int&x){//递归求解，超时 >_<
        if(stair_kinds[x]!=0){//如果对应的阶梯的种类数已经被更新了，就直接返回
            return stair_kinds[x];
        }
        if(x==0){
            return 1;
        }
        long long int kind=0;
        for(int i=1;i<=k&&x-i>=0;i++){//对于x级台阶，向下寻找其上一步的可能数
            if(stairs[x-i]){
                kind+=f(x-i)%998244353;
            }
        }
        stair_kinds[x]=kind%998244353;
        return stair_kinds[x];
    }
    void solve(){
        long long int kind_sum=0;
        for(int i=1;i<=n;i++){
            kind_sum+=stair_kinds[i-1];//加上上一个台阶的情况数;
            if(i-k-1>=0){
                kind_sum-=stair_kinds[i-k-1];
            }
            if(stairs[i]){
                stair_kinds[i]=kind_sum%mod;
            }
        }
        cout<<stair_kinds[n]<<endl;
    }
};
int main(){
    Deal().solve();
}