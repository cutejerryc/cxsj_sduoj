#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int g;
    vector<int>a(n,0);
    vector<int>re(n,0);
    for(int i=0;i<n;i++){
        cin>>g;
        a[g]++;
        re[i]=a[g];
    }
    for(int i=0;i<n;i++){
        cout<<re[i]<<' ';
    }
    
}