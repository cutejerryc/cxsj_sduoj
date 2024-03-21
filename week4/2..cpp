#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int gcd(int a,int b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a, int b) {
    return (a*b)/gcd(a,b);
}
int main(){
    cin>>n>>x>>y;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    int tmp=x;
    if(x>y){
        x=y;
        y=tmp;
    }
    int t=0;
    t+=x;
    n-=1;
    int g=lcm(x,y);
    int sum_t=g/x+g/y;
    while(n>=sum_t){
        n-=sum_t;
        t+=g;
    }
    for(int i=1;n>0;i++){
        t++;
        if(i%x==0){
            n--;
        }
        if(n==0){
            break;
        }
        if(i%y==0){
            n--;
        }
        if(n==0){
            break;
        }
    }
    cout<<t<<endl;
}