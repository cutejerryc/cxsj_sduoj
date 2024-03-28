# 山东大学程序设计思维与实践作业-Week4
**仅作参考，切莫照搬，有查重**
- 代码题目
  - 1
  ```shell
  git clone https://github.com/W1412X/cxsj_sduoj.git
  ```
  - 2  
前往[点击此处](https://github.com/W1412X/cxsj_sduoj.git)获取

- 简答题目
# 1
> 先将其右移到需要改变的前一位，此时可以计算得到右移丢失部分的值，对末位取反并乘以2的右移次数次方，得到的是丢失了右移部分的值，在加上右移部分的值即可得到结果。  
- 代码如下:
```cpp
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
```
# 2
- 单调栈
  - 以单调递增栈为例，在入栈过程中需要保持入栈元素小于栈顶元素，如果遇到不符合条件的则出栈直至栈为空或者满足条件，则继续入栈，由此可见每个元素都需要经历一次进栈，一次出栈，故时间复杂度为
$$
O(n)
$$
- 单调队列
  - 以单调递增队列为例，队列中从队头到队尾是递增的。每次插入都会判断当前插入的元素e与队尾元素tail的大小关系
    - 如果e>tail，则可以直接添加到队尾
    - 反之，需要执行出队操作，直至队列为空或者tail<e
  - 可见每个元素也是仅需入队出队一次，故时间复杂度为
$$
O(n)
$$

# 3
## 解法
- 首先利用质因数分解求出所有的质因数幂数，具体流程如下
  - 由于给出的数据范围 1=<c<=100，则可以直接写出一百以内的质数集合，之后由于所有的数都是由c次幂产生的，则其一定可以分解为这个质数集合的积
  - 对n个数序列，生成一个n x 25的二维数组，第二维代表对数列中的每一个数可以分解的质因数的次幂
  - 每次更新只需要更新位于区间左边缘以及位于区间右边缘的右侧一位的数字，对应的如果区间为[l,r]，只需要对第l个数的质数的次幂+b，第r+1个数的质数的次幂-b，这样之后直接求前n项和就可以得到第n个数字的对应的质数的次幂
  - 之后对于每一个质数寻找其次幂的最小值即可
- 利用取模的性质(a*b)mod(c)=(a mod c) \* (b mod c)
  - 我们经过质因数分解得到的质数直接根据题目中给出的式子相乘即为最后的答案
## 时间复杂度
  - 解释
    - 得到质因数以及其对应的次幂的数组的时间为25*m,
    - 找出每个质因数最小次幂的时间为25*n
    - 快速幂的时间复杂度最大为log(10^9)
  - 时间复杂度
$$
O(m+n+log(10^9))
$$
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    long long int mod=1e9+7;
    long long int n,m;
    long long int l,r,c,b;
    int prime_set[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    Deal(){
        cin>>n>>m;
    }
    long long int quick_pow(long long int a,long long int n){
        long long int ans=1;
        while(n){
            if(n&1){
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            n>>=1;
        }
        return ans;
    }
    void solve(){
        long long pows[n+2][25]={0};
        for(int i=0;i<m;i++){
            cin>>l>>r>>c>>b;
            //在这里得到分解后所有素数对应的幂次，存储在pows中,powsz
            for(int u=0;u<25;u++){
                if(c<prime_set[u]){
                    break;
                }else{
                    while(c%prime_set[u]==0){//这里只在每次输入的区间的第一个和区间的最后一个的下一个作标记
                        pows[l][u]+=b;//每可以被这个素数整除一次，对应的c^b可以被整除b次
                        pows[r+1][u]-=b;
                        c/=prime_set[u];
                    }
                }
            }
        }
        long long int min_prime_pows[25]={0};
        for(int i=0;i<25;i++){//初始化最小素数幂次的数组，以第一个为标准
            min_prime_pows[i]=pows[1][i];
        }
        for(int i=0;i<25;i++){//对每一个素数求其最小的幂次
            for(int u=2;u<=n;u++){//由于之前保存的是每个区间的第一个和最后一个的下一个，所以只需要累加就可以得到每次输入的数的对应的次数的次幂
                pows[u][i]+=pows[u-1][i];
                min_prime_pows[i]=min(pows[u][i],min_prime_pows[i]);
            }
        }
        long long int ans=1;
        for(int i=0;i<25;i++){//直接对素数prime_set做次幂即可，最小次幂数据存储在min_prime_pow中
            ans=ans*quick_pow(prime_set[i],min_prime_pows[i])%mod;
        }
        cout<<ans<<endl;
    }
};
int main(){
    Deal d= Deal();
    d.solve();
}
```
