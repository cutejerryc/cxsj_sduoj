#include<iostream>
#include<sstream>
using namespace std;
void deal_string_stream(){
    std::string s;
    int sum=0;
    int g;
    while(std::getline(std::cin,s)){
        std:stringstream ss(s);
        while(!ss.eof()){
            ss>>g;
            sum+=g;
        }
        cout<<sum<<endl;
        sum=0;
    }
}
int main(){
    deal_string_stream();
}