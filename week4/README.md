# 山东大学程序设计思维与实践作业-Week4
**仅作参考，切莫照搬，有查重**
- 代码题目
  - 1
  ```shell
  git clone https://github.com/W1412X/cxsj_sduoj.git
  ```
  - 2  
前往https://github.com/W1412X/cxsj_sduoj.git获取

- 简答题目
# 1
- 设置过小会导致二分的次数过多，时间复杂度升高
- 设置过大会导致二分的精度不够，从而对应的结果不准确
# 2
1) 对于编程题2，可能会出现仅需要1份复印件
2) 对于编程题3，可能会出现所有商店的价格均相同的情况
# 3
## 解释
- 在绳子最长的范围内进行二分，计算每次取中间值可以得到的绳子段数
  - 如果段数多，则取较大的区间继续
  - 反之取较小的区间
- 当区间两个端点之差小于实验要求的误差时，终止循环
## 时间复杂度
- 
$$
O(n\log(10^{13}))
$$
- 每次查找判断的时间复杂度为O(n),二分的时间复杂度为log(1e13)
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,k;
double a[100000];
bool if_ok(double x){//判断个数
    int num=0;
    for(int i=0;i<n;i++){
        num+=int(a[i]/x);
    }
    return num>=k;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    double l = 0, r = 1e7;
    while(l+1e-6<r)
    {
        double mid=(l+r)/2;
        if(if_ok(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
    return 0;
}
```
# 4
## 解释
- 首先进行排序
- 然后从排序后的序列的第一个元素x开始，依次向后查找第一个在(x,x+k]之内的数，操作数加一并继续判断下一个数字
## 时间复杂度
- 时间复杂度
$$
O(n\log(n))
$$
- 解释
  - 排序的时间复杂度为O(nlog(n)),而之后的判断循环的时间复杂度为O(n)
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());//排序

    int operations = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u = i + 1;
        if (u < n && a[u] - a[i] <= k) {//判断是否存在
            ++u;
        }
        operations += u - i - 1;
    }
    cout << operations << endl;
    return 0;
}
```