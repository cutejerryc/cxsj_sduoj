# 3
## 题目描述

给定数列 a1​,a2​,…,an​，你需要依次进行 q 个操作，操作有两类：

+   `1 i x`：给定 i,x，将 ai​ 加上 x；
+   `2 l r`：给定 l,r，求 ∑i\=lr​ai​ 的值（换言之，求 al​+al+1​+⋯+ar​ 的值）。

## 输入格式

第一行包含 2 个正整数 n,q，表示数列长度和询问个数。保证 1≤n,q≤106。  
第二行 n 个整数 a1​,a2​,…,an​，表示初始数列。保证 ∣ai​∣≤106。  
接下来 q 行，每行一个操作，为以下两种之一：

+   `1 i x`：给定 i,x，将 a\[i\] 加上 x；
+   `2 l r`：给定 l,r，求 ∑i\=lr​ai​ 的值。

保证 1≤l≤r≤n, ∣x∣≤106。

## 输出格式

对于每个 `2 l r` 操作输出一行，每行有一个整数，表示所求的结果。

## 样例

### 输入样例

`3 2 1 2 3 1 2 0 2 1 3`

### 输出样例

`6`

## 数据范围

对于所有数据，1≤n,q≤106, ∣ai​∣≤106, 1≤l≤r≤n, ∣x∣≤106。 

# 4
## 题目描述

sys 参加了一场 AI 算法大赛，大赛要求参赛者提供一个程序，后台的评测系统会使用相同的数据对所有提交程序进行评测，通过程序的**运行时间**与**内存占用**来衡量一个算法的好坏。

比赛的成绩计算方法为，给每一个程序进行打分，对于一个程序来说，该程序的得分为：**运行时间**与**内存占用**均小于等于该程序的程序的数量。

现在需要你来计算，成绩为 0,1,…n−1 的程序的数量分别为多少。

## 输入格式

第一行一个整数 N，表示程序的数目；  
接下来 N 行给出每个程序的运行时间与内存占用，用两个空格隔开的整数表示；  
不会有两个程序的运行时间与内存占用均相同。

## 输出格式

n 行，每行一个整数，分别是得分为 0，1，2，…，n−1 的程序的数目。

## 样例

### 输入

`5 1 1 5 1 7 1 3 3 5 5`

### 输出

`1 2 1 1 0`

### 样例解释

得分为 0 的程序为 (1 1)

得分为 1 的程序为 (5 1) (3 3)

得分为 2 的程序为 (7 1)

得分为 3 的程序为 (5 5)

得分为 4 的程序为：无

## 数据范围

对于全部数据，1≤n≤106，0≤运行时间,内存占用≤106。

# 5
## 题目描述

lzh 在火星开了一家饭店，为了吸引顾客，饭店会不定期在菜谱中加入新菜，每个菜都有一个美味度 l(0≤l<p)。

饭店使用手机进行点餐，手机上展示的菜谱会按照更新的顺序逆序排列。由于不同顾客的手机屏幕分辨率大小不同，所以能够显示在第一屏的菜谱的数量也不同。根据调查发现，火星用户只会在第一屏的菜品中选择美味度最高的购买。

现在按照时间顺序输入 m 个添加菜品或顾客点菜的操作，请输出每位点菜顾客所点的菜的美味度。

## 输入格式

第一行有两个正整数 m,p，意义如题目描述；

接下来 m 行，每一行表示一个操作。

+   如果该行的内容是 `Q L`，则表示有顾客进行了点菜，该顾客的手机屏幕可以显示 L 个菜品；
+   如果是 `A t`，则表示加入了新的菜品，菜品的美味度是 (t+a)modp。
    +   t 是输入的参数
    +   a 是在这个添加操作之前最后一个点菜操作的答案（如果之前没有点菜操作，则 a\=0）。

数据保证第一个操作一定是添加菜品。在顾客点菜时，L\>0 且不超过当前已有菜品的数量。

## 输出格式

对于每一个点菜操作，输出一行。该行只有一个数，即当前屏幕中美味度最大的菜品的美味度。

## 样例

### 输入

`10 100 A 97 Q 1 Q 1 A 17 Q 2 A 63 Q 1 Q 1 Q 3 A 99`

### 输出

`97 97 97 60 60 97`

## 数据范围

对于全部数据，1≤m≤2×105,1≤p≤2×109,0≤t<p。
# 1
- 不可以，因为树状数组每个节点内存储的元素是一些元素的和，要计算平均值要知道元素个数，而且一个节点内存储的元素和对应的元素一般也不是连续的，如果在节点加上一个属性就是这个节点对应的计算的和的元素个数应该可以
# 2
## 解法
- 首先根据时间进行排序，然后对因使用的内存做处理。
- 维护一个内存树状数组
  - 每个索引`ind`对应的元素是内存小于等于ind的程序个数
- 维护一个分数数组，对应的索引为`ind`的元素为得到此得分的程序个数
- 因为已经按照时间排序了，所以无需担心会在计算某一个程序时之后的一些程序的情况  
## 时间复杂度
$$
O(n \cdot \log{n})
$$  
- 树状数组添加和查询的时间复杂度为  $\log{n}$
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std; 
class TreeArray{
    private:
    long long int lowbit(const long long int&x){
        return (x&(-x));
    }
    public:
    vector<long long int>a;
    long long int n,q;
    TreeArray(){};
    TreeArray(const long long int &n_){
        n=n_;
        long long int g;
        a=vector<long long int>(n+1,0);
    }
    void add(const long long int&ind,const long long int&k){
        for(long long int i=ind;i<=1e6+1;i+=lowbit(i)){
            a[i]+=k;
        }
    }
    long long int search(const long long int&begin,const long long int&end){
        long long int ans=0;
        for(long long int i=begin-1;i;i-=lowbit(i)){
            ans-=a[i];
        }
        for(long long int i=end;i;i-=lowbit(i)){
            ans+=a[i];
        }
        return ans;
    }
    long long int sum(const long long int&end){
        long long int ans=0;
        for(long long int i=end;i;i-=lowbit(i)){
            ans+=a[i];
        }
        return ans;
    }
};
class Program{
    public:
    long long int time;
    long long int mem;
    Program(){}
    Program(const int&t,const int&m):time(t),mem(m){}
    bool operator <(const Program&other){
        return time<other.time || (time==other.time&&mem<other.mem);
    }
};
class Deal{
    public:
    long long int n;
    TreeArray ta;
    vector<Program>p;
    Deal(){
        cin>>n;
        ta=TreeArray(1e6+1);
        int a,b;
        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            p.push_back(Program(a,b));
        }
        sort(p.begin(),p.end());
    }
    void solve(){
        vector<long long int>ans(1e6+1,0);
        for(int i=0;i<n;i++){
            ta.add(p[i].mem+1,1);
            ans[ta.sum(p[i].mem+1)]++;
        }
        for(int i=1;i<=n;i++){
            printf("%d\n",ans[i]);
        }
    }
};
int main(){
    Deal().solve();
}
```