#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    char f=s[0];
    char se=s[1];
    char t=s[2];
    if( f==se && se==t ){
        cout<<"Won";
    }else{
        cout<<"Lost";
    }
}