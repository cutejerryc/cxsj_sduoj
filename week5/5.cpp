#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    long long int mod=1e9+7;
    long long int n,m;
    long long int l,r,c,b;
    int prime_set[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    Deal(){
        cin>>n>>m;
    }
    long long int quick_pow(long long int a,long long int n){
        long long int ans=1;
        while(n){
            if(n&1){
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            n>>=1;
        }
        return ans;
    }
    void solve(){
        long long pows[n+2][25]={0};
        for(int i=0;i<m;i++){
            cin>>l>>r>>c>>b;
            //在这里得到分解后所有素数对应的幂次，存储在pows中,powsz
            for(int u=0;u<25;u++){
                if(c<prime_set[u]){
                    break;
                }else{
                    while(c%prime_set[u]==0){//这里只在每次输入的区间的第一个和区间的最后一个的下一个作标记
                        pows[l][u]+=b;//每可以被这个素数整除一次，对应的c^b可以被整除b次
                        pows[r+1][u]-=b;
                        c/=prime_set[u];
                    }
                }
            }
        }
        long long int min_prime_pows[25]={0};
        for(int i=0;i<25;i++){//初始化最小素数幂次的数组，以第一个为标准
            min_prime_pows[i]=pows[1][i];
        }
        for(int i=0;i<25;i++){//对每一个素数求其最小的幂次
            for(int u=2;u<=n;u++){//由于之前保存的是每个区间的第一个和最后一个的下一个，所以只需要累加就可以得到每次输入的数的对应的次数的次幂
                pows[u][i]+=pows[u-1][i];
                min_prime_pows[i]=min(pows[u][i],min_prime_pows[i]);
            }
        }
        long long int ans=1;
        for(int i=0;i<25;i++){//直接对素数prime_set做次幂即可，最小次幂数据存储在min_prime_pow中
            ans=ans*quick_pow(prime_set[i],min_prime_pows[i])%mod;
        }
        cout<<ans<<endl;
    }
};
int main(){
    Deal d= Deal();
    d.solve();
}