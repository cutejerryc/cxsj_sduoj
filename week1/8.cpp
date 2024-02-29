#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int g2(int a){
    string tmp=std::to_string(a);
    std::sort(tmp.begin(),tmp.end());
    return std::stoi(tmp);
}
int g1(int a){
    string tmp=std::to_string(a);
    std::sort(tmp.begin(),tmp.end());
    std::reverse(tmp.begin(),tmp.end());
    return std::stoi(tmp);
}
int f(int a){
    return g1(a)-g2(a);
}
int main(){
    int a;
    int k;
    cin>>a>>k;
    for(int i=0;i<k;i++){
        a=f(a);
    }
    cout<<a;
}
