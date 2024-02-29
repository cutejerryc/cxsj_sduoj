#include<iostream>
using namespace std;
int main(){
    long long a,b;
    while(cin>>a>>b){
        cout<<a+b<<endl;
        if(cin.eof()){
            break;
        }
    }
}