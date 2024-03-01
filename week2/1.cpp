#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int g;
    vector<int>a;
    for(int i=0;i<n;i++){
        cin>>g;
        a.push_back(g);
    }
    int re=0;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++){
        if(a[i+1]-a[i]==1){
            re++;
        }
    }
    cout<<re<<endl;
}