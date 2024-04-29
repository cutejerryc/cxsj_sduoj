#include<bits/stdc++.h>
using namespace std;
bool a_s[27]={false};
class String{
    public:
    int n;
    string s;
    int l,r;
    int re;
    String(const int&n_){
        n=n_;
        cin>>s;
        for(int i=0;i<n;i++){
            if(a_s[s[i]-97]){
                s[i]='$';
            }
        }
    }
    String(){};
    int mid_expand_j(const int&i){
        re=1;
        l=i-1,r=i+1;
        while(l>=0&&r<n){
            if(s[l]==s[r]){
                re+=2;
            }else{
                break;
            }
            l--,r++;
        }
        return re;
    }
    int mid_expand_o(const int&i){
        re=0;
        l=i,r=i+1;
        while(l>=0&&r<n){
            if(s[l]==s[r]){
                re+=2;
            }else{
                break;
            }
            l--,r++;
        }
        return re;
    }
};
class Deal{
    public:
    String s;
    int n;
    Deal(){
        cin>>n;
        a_s['a'-97]=true,a_s['e'-97]=true,a_s['i'-97]=true,a_s['o'-97]=true,a_s['u'-97]=true;
        s=String(n);
    }
    void solve(){
        int _max=1;
        int tmp;
        for(int i=0;i<n;i++){
            tmp=max(s.mid_expand_j(i),s.mid_expand_o(i));
            if(tmp>_max){
                _max=tmp;
            }
        }
        cout<<_max<<endl;
    }
};
int main(){
    Deal().solve();
}