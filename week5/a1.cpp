#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int num;
    Deal(int n):num(n){}
    int solve(int i){
        int ori_num=num;
        i=i-1;
        int times=0;//记录右移的次数
        while(times<i){
            times++;
            num>>=1;
        }
        int tmp_num=num*pow(2,times);
        int dif=ori_num-tmp_num;
        num=num^1;
        return num*pow(2,times)+dif;
    }
};
int main(){
    Deal d=Deal(11);
    cout<<d.solve(2);
}