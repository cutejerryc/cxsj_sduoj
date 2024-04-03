#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n;
    string s="";
    unordered_map<char,bool>vowel_set;
    string result="";
    int max_length=0;
    Deal(){
        cin>>n;
        char c;
        cin>>s;
        vowel_set['a']=true;
        vowel_set['e']=true;
        vowel_set['i']=true;
        vowel_set['o']=true;
        vowel_set['u']=true;
    }
    void solve(){
        int continuous_length=0;
        for(int i=0;i<s.size();i++){
            if(vowel_set.find(s[i])!=vowel_set.end()&&continuous_length==0){//是第一个元音
                continuous_length++;
                result+=s[i];
            }else{
                if(vowel_set.find(s[i])==vowel_set.end()){
                    result+=s[i];
                    continuous_length=0;
                }
            }
        }
        cout<<result;
    }
};
int main(){
    Deal().solve();
}