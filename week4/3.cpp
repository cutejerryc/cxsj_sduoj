#include<bits/stdc++.h>
using namespace std;
long long int a[100008];
long long int n,t;
pair<long long int,long long int> deal(){
    long long int last_numb;
    long long int times=0;
    long long int profit_now=0;
    long long int sum_profit=0;
    last_numb=a[0];
    for(long long int i=1;i<n;i++){
        if(a[i]>=last_numb){//如果是递增(为了保证最小的次数，把等于也酸进取)的
            profit_now+=a[i]-last_numb;
        }else {//否则
            if(profit_now!=0){
                times+=2;
                sum_profit+=profit_now;
                profit_now=0;
            }
        }
        last_numb=a[i];
    }
    if(profit_now!=0){
        sum_profit+=profit_now;
        times+=2;
    }
    return make_pair(sum_profit,times);
}
int main(){
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;
        for(long long int u=0;u<n;u++){
            cin>>a[u];
        }
        pair<long long int,long long int>re=deal();
        cout<<re.first<<' '<<re.second<<endl;
    }
}