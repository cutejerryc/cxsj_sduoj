#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double a,b;
    cin>>a>>b;
    double c=b-a;
    double re=std::abs(100*c/a);
    cout<<std::fixed<<std::setprecision(3)<<re;
}