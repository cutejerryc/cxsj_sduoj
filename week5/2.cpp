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
    int n;
    string s="";
    vector<MString>a;
    vector<MString>b;
    int min_l,min_r;
    int min_len=INT32_MAX;
    Deal(){
        cin>>n;
        cin>>s;
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
    //双指针
    void recursion(int l,int r){
        if(l>=r){
            return;
        }
        if(a[r]-b[l]){
            if(r-l+1<min_len){
                min_len=r-l+1;
                min_l=l;
                min_r=r;
                recursion(l+1,r);
                recursion(l,r-1);
            }else{
                return;
            }
        }
    }
    //rule way
    void rule_way(){
        int l=0,r=0;
        while(l<s.size()-25){
            if(min_len==26){
                break;
            }
            if(a[r]-b[l]||r==s.size()-1){
                if((a[r]-b[l])&&(min_len>=r-l+1)){
                    min_len=r-l+1;
                    min_l=l;
                    min_r=r;
                }
                l++;
            }
            if(!(a[r]-b[l])&&r<s.size()-1){
                r++;
            }
        }
    }
    void solve(){
        rule_way();
        cout<<min_len<<endl;
    }
};
int main(){
    Deal d=Deal();
    d.solve();
}