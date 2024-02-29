#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(i%2==0){
            if(s[i]>=97&&s[i]<=122){
                continue;
            }else{
                cout<<"No";
                return 0;
            }
        }else{
            if(s[i]>=65&&s[i]<=90){
                continue;
            }else{
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}