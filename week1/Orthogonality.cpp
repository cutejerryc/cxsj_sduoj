#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long int>a,b;
    int g;
    for(int i=0;i<n;i++){
        cin>>g;
        a.push_back(g);
    }
    for(int i=0;i<n;i++){
        cin>>g;
        b.push_back(g);
    }
    long long int re=0;
    for(int i=0;i<n;i++){
        re+=b[i]*a[i];
    } 
    cout<<(re==0?"Yes":"No");
}