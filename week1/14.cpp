#include<iostream>
using namespace std;
int main(){
    int a;
    int g;
    int s=0;
    while(cin>>a){
        for(int i=0;i<a;i++){
            cin>>g;
            s+=g;
        }
        cout<<s<<endl;
        s=0;
        if(cin.eof()){
            break;
        }
    }
}