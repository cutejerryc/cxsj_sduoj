#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    long long int n;
    vector<long long int>a;
    long long int max_area=0;
    Deal(){
        cin>>n;
        long long int g;
        for(long long int i=0;i<n;i++){
            cin>>g;
            a.push_back(g);
        }
    }
    void solve(){
        stack<long long int>sk;
        long long int l=-1;
        for(long long int i=0;i<n;i++){
            if(sk.empty()){
                sk.push(i);
                continue;
            }
            if(a[i]>=a[sk.top()]){
                sk.push(i);
            }else{
                long long int r;
                r=sk.top();
                while(!sk.empty()&&a[i]<a[sk.top()]){
                    long long int tmp_p=sk.top();
                    sk.pop();
                    if(!sk.empty()){
                        l=sk.top();
                    }else{
                        l=-1;
                    }
                    long long int area=(r-l)*a[tmp_p];
                    if(max_area<=area){
                        max_area=area;
                    }
                }
                sk.push(i);
            }
        }
        long long int r=n-1;
        while(!sk.empty()){//剩余元素全部出栈
            long long int h=a[sk.top()];
            sk.pop();
            long long int l;
            if(!sk.empty()){
                l=sk.top();
            }else{
                l=-1;
            }
            long long int area=((r-l))*h;
            if(max_area<=area){
                max_area=area;
            }
        }
        cout<<max_area<<endl;
    }
};
int main(){
    Deal().solve();
}