#include<bits/stdc++.h>
using namespace std;
bool if_prime(int n){
    if(n<2){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int n,k;
int a[100];
int num=0;
void deal(int k,int i,int sum,bool if_choose){
    if(k==0){
        if(if_prime(sum)){
            num++;
        }
        return;
    }
    if(i>=n){
        return;
    }
    if(if_choose){
        int i1=i+1;
        int k1=k-1;
        deal(k1,i1,sum+a[i],true);
        deal(k1,i1,sum+a[i],false);
    }else{
        int i1=i+1;
        int k1=k;
        deal(k1,i1,sum,true);
        deal(k1,i1,sum,false);      
    }
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    deal(k,0,0,true);
    deal(k,0,0,false);
    cout<<num/2<<endl;
}