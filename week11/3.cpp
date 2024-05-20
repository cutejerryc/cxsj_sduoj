#include<bits/stdc++.h>
using namespace std; 
class TreeArray{
    private:
    long long int lowbit(const long long int&x){
        return (x&(-x));
    }
    public:
    vector<long long int>a;
    long long int n,q;
    TreeArray(){};
    TreeArray(const long long int &n_){
        n=n_;
        long long int g;
        a=vector<long long int>(n+1,0);
        for(long long int i=1;i<=n;i++){
            cin>>g;
            add(i,g);
        }
    }
    void add(const long long int&ind,const long long int&k){
        for(long long int i=ind;i<=n;i+=lowbit(i)){
            a[i]+=k;
        }
    }
    long long int search(const long long int&begin,const long long int&end){
        long long int ans=0;
        for(long long int i=end;i;i-=lowbit(i)){
            ans+=a[i];
        }
        for(long long int i=begin-1;i;i-=lowbit(i)){
            ans-=a[i];
        }
        return ans;
    }
};
class Deal{
    public:
    long long int n,q;
    TreeArray ta;
    Deal(){
        cin>>n>>q;
        ta=TreeArray(n);
    }
    void solve(){
        long long int a,b,c;
        for(long long int i=0;i<q;i++){
            cin>>a>>b>>c;
            if(a==1){
                ta.add(b,c);
            }else{
                cout<<ta.search(b,c)<<endl;
            }
        }
    }
};
int main(){
    Deal().solve();
}