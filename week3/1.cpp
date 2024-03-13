#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    vector<bool>childs(n,true);
    int p=-1;
    int i=0;
    int num=0;
    int count=1;
    while(1){
        if(childs[i%n]){
            if(count%k==0||count%10==k){
                childs[i%n]=false;
                num++;
            };
            if(num==n-1){
                break;
            }
            count++;
        }
        i++;
    }
    for(int i=0;i<n;i++){
        if(childs[i]){
            cout<<i+1<<endl;
            break;
        }
    }
}