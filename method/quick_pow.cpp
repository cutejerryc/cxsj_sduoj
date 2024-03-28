#include<bits/stdc++.h>
using namespace std;
template <class T>
class QuickPow{
    public:
    int q_recursion(int a,int n){//传入参数为底数和幂数
        if(n==0){
            return 1;
        }else if(n%2==1){//如果是奇数
            return q_recursion(a,n-1)*a;
        }else{//n是偶数，直接二分
            int tmp=q_recursion(a,n/2);
            return tmp*tmp;
        }
    }
    int q_recursion_mod(int a,int n,int mod){
        if(n==0){
            return 1;
        }else if(n%2==1){
            return q_recursion_mod(a,n)*a%mod;
        }else{
            int tmp=q_recursion_mod(a,n,mod);
            return tmp*tmp%mod;
        }
    }
    int q_generate(int a,int n){//利用二进制
        int ans=1;
        while(n){
            if(n&1){
                ans*=a;
            }
            a*=a;
            n>>1;
        }
        return ans;
    }
    T q_T_generate(T a,int n,T unit){//对于任意类型的数据进行快速幂的操作(包括矩阵)
        T ans=unit;//赋值为单位元
        while(n){
            if(n&1){
                ans=ans*a;//需要重载*运算符
            }
            n>>1;
            a=a*a;
        }
    }
};
int main(){

}