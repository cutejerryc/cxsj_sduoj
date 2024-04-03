#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n;
    string s="";
    unordered_map<char,bool>vowel_set;
    int max_length=0;
    Deal(){
        cin>>n;
        char c;
        getchar();
        for(int i=0;i<n;i++){
            c=getchar();
            s+=c;
        }
        vowel_set['a']=true;
        vowel_set['e']=true;
        vowel_set['i']=true;
        vowel_set['o']=true;
        vowel_set['u']=true;
    }
    void solve(){
        int continuous_length=0;
        for(int i=0;i<s.size();i++){
            if(vowel_set.find(s[i])!=vowel_set.end()){
                continuous_length++;
            }else{
                max_length=max_length>continuous_length?max_length:continuous_length;
                continuous_length=0;
            }
        }
        cout<<max_length;
    }
};
int main(){
    Deal().solve();
}