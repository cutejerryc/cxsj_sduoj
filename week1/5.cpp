#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    int g;
    int x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>g;
        if(g==x){
            continue;
        }else{
            cout<<g<<" ";
        }
    }
}