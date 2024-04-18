#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n;
    vector<int>a;
    vector<int>re;
    Deal(){
        cin>>n;
        int g;
        for(int i=0;i<n;i++){
            cin>>g;
            a.push_back(g);
        }
    }
    void solve(){
        for(int i=0;i<n;i++){
            if(i==0){
                re.push_back((a[0]+a[1])/2);
            }else if(i==n-1){
                re.push_back((a[n-1]+a[n-2])/2);
            }else{
                re.push_back((a[i]+a[i-1]+a[i+1])/3);
            }
        }
        for(int i=0;i<n;i++){
            cout<<re[i]<<' ';
        }
        cout<<endl;
    }
};
int main(){
    Deal().solve();
}
