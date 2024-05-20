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
    }
    void add(const long long int&ind,const long long int&k){
        for(long long int i=ind;i<=1e6+1;i+=lowbit(i)){
            a[i]+=k;
        }
    }
    long long int search(const long long int&begin,const long long int&end){
        long long int ans=0;
        for(long long int i=begin-1;i;i-=lowbit(i)){
            ans-=a[i];
        }
        for(long long int i=end;i;i-=lowbit(i)){
            ans+=a[i];
        }
        return ans;
    }
    long long int sum(const long long int&end){
        long long int ans=0;
        for(long long int i=end;i;i-=lowbit(i)){
            ans+=a[i];
        }
        return ans;
    }
};
class Program{
    public:
    long long int time;
    long long int mem;
    Program(){}
    Program(const int&t,const int&m):time(t),mem(m){}
    bool operator <(const Program&other){
        return time<other.time || (time==other.time&&mem<other.mem);
    }
};
class Deal{
    public:
    long long int n;
    TreeArray ta;
    vector<Program>p;
    Deal(){
        cin>>n;
        ta=TreeArray(1e6+1);
        int a,b;
        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            p.push_back(Program(a,b));
        }
        sort(p.begin(),p.end());
    }
    void solve(){
        vector<long long int>ans(1e6+1,0);
        for(int i=0;i<n;i++){
            ta.add(p[i].mem+1,1);
            ans[ta.sum(p[i].mem+1)]++;
        }
        for(int i=1;i<=n;i++){
            printf("%d\n",ans[i]);
        }
    }
};
int main(){
    Deal().solve();
}