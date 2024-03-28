#include<bits/stdc++.h>
using namespace std;
class MString{
    public:
    vector<int>s;
    MString(const vector<int>&s_i){
        s=s_i;
    }
    MString(){
        s=vector<int>(26,0);
    }
    int operator [](int index){
        return this->s[index];
    }
    bool operator -(MString other){
        for(int i=0;i<s.size();i++){
            if(s[i]-other[i]<=0){
                return false;
            }
        }
        return true;
    }
    MString operator +(const char&c){
        s[c-65]+=1;
        return MString(s);
    }
};
class Deal{
    public:
    int n,m;
    string s;
    vector<MString>a;
    vector<MString>b;
    Deal(){
        cin>>n;
        cin>>s;
        cin>>m;
        MString s_tmp;
        for(int i=0;i<s.size();i++){
            s_tmp=s_tmp+s[i];
            a.push_back(s_tmp);
            if(i==0){
                b.push_back(MString());
            }else{
                b.push_back(a[i-1]);
            }
        }
    }
    void enquire(int l,int r){
        l-=1;r-=1;
        if(a[r]-b[l]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    void solve(){
        int l,r;
        for(int i=0;i<m;i++){
            cin>>l>>r;
            enquire(l,r);
        }
    }
};
int main(){
    Deal d=Deal();
    d.solve();
}