#include<bits/stdc++.h>
using namespace std;
int n,k;
double a[100000];
bool if_ok(double x){
    int num=0;
    for(int i=0;i<n;i++){
        num+=int(a[i]/x);
    }
    return num>=k;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    double l = 0, r = 1e7;
    while(l+1e-6<r)
    {
        double mid=(l+r)/2;
        if(if_ok(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
    return 0;
}