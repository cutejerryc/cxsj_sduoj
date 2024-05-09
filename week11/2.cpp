#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    vector<int>a;
    int n;
    Deal(){
        cin>>n;
        int g;
        for(int i=0;i<n;i++){
            cin>>g;
            a.push_back(g);
        }  
        sort(a.begin(),a.end());
    }
    void solve(){
        cout<<a[a.size()-1]<<' ';
        if(n%2==0){
            int sum=a[n/2-1]+a[n/2];
            if(sum%2==0){
                cout<<sum/2<<' ';
            }else{
                cout<<fixed<<setprecision(1)<<sum/2.0<<' ';
            }
        }else{
            cout<<a[n/2]<<' ';
        }
        cout<<a[0]<<endl;
    }
};
int main(){
    Deal().solve();
}