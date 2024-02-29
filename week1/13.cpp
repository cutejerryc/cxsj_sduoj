#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int n1;
    int g;
    int s=0;
    for(int i=0;i<n;i++){
        cin>>n1;
        for(int u=0;u<n1;u++){
            cin>>g;
            s+=g;
        }
        cout<<s<<endl;
        s=0;
    }
}