## 1
$$
f_4(n)=n^8+n!\\
f_6(n)=e^n+{e}^{16}\\
f_5(n)={n}^{16}+n{\log n}\\
f_3(n)=n^8\\
f_2(n)=2^{\log n }\\
f_1(n)=\log(\log(n))
$$

## 2
时间复杂度为

* $$
  O(\sqrt{n})
  $$

解释:

- 循环的终止条件为
  
  $$
  j>\sqrt{n}
  $$
## 3
- 时间复杂度为

  $$
  O(n^2\bullet\log(n^2))

  $$
- 解释

  - 在while中每次执行k/2，故while循环的执行次数为

  $$
  \log(n^2)

  $$

  - 在for循环中，所执行的次数为

  $$
  n^2

  $$

  - 两者相乘，既得总的时间复杂度为

  $$
  O(n^2\bullet\log(n^2))

  $$

## 4
- 时间复杂度

  $$
  O(\log_3(n))

  $$
- 解释

  - 对于n为3的次幂，则执行次数为

    $$
    \log_3(n)

    $$
  - 对于n不为3的次幂，执行次数也为

  $$
  \log_3(n)

  $$

## 5
- 代码逻辑本身有问题，样例数据不全面
- 代码时间复杂度过高，导致出现TLE超时
- 输出格式有细微差别

## 6
### 利用fopen  
  ```cpp
void fre_open(){
     string s;
    // 重定向输入流
    freopen("in.txt", "r", stdin);
    cin>>s;
    cout<<"in.txt cin->"<<s;
    // 重定向输出流
    freopen("out.txt", "w", stdout);
    cout<<"out.txt cout";
}
  ```
### 利用ifstream ofstream
  ```cpp
void io_fstream(){
  //重定向输入
  ifstream in("in.txt");
  streambuf *inbuf=cin.rdbuf();
  cin.rdbuf(in.rdbuf());//输入的缓冲区设置为in的
  string s;
  std::cin>>s;
  cout<<s;
  cin.rdbuf(inbuf);//恢复
  //重定向输出
  ofstream out("out.txt");
  streambuf *outbuf=cout.rdbuf();
  cout.rdbuf(out.rdbuf());
  cin>>s;
  cout<<s;
}
  ```
## 7
### 解法
  - 在输入时确定对应的最左端的人位置l和最右端的人位置r
  - 对l与r之间的所有位置遍历计算代价，并与之前的最小代价比较，取较小者作为新的最小代价
### 时间复杂度
$$
O((r-l)\bullet n)
$$
- 解释 
  - 对于每一个遍历的点计算最小代价的操作次数为n，而遍历的次数为r-l
```cpp
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int get_val(int&u,vector<int>&a){//计算一个点的代价
    int re=0;
    for(int i=0;i<a.size();i++){
        re+=pow((a[i]-u),2);
    }
    return re;
}
int main(){
    int n;
    int l=INT32_MAX,r=INT32_MIN;
    int min_val=INT32_MAX;
    vector<int>a;
    cin>>n;
    int g;
    for(int i=0;i<n;i++){
        cin>>g;
        if(g<l){//更新l
            l=g;
        }
        if(g>r){//更新r
            r=g;
        }
        a.push_back(g);
    }
    for(int i=l;i<=r;i++){//在l与r之间寻找最小代价点
        int tmp=get_val(i,a);
        if(tmp<min_val){
            min_val=tmp;
        }
    }
    cout<<min_val;
    return 0;
}
```
## 8
### 解法
  - 输入以整数的形式输入
  - g1与g2的转换通过将整数转换为字符串，对字符串进行排序，将排序后的字符串转换为整数
  - 根据输入的k设置for循环的次数，利用g1，g2，f的运算规则进行迭代
### 时间复杂度
$$
O(n\log(n))
$$
  - 解释
    - 代码中使用到的sort函数的时间复杂度为
    $$
    O(n\log(n))
    $$
    - 使用到的reverse，to_string,stoi函数的时间复杂度均为
    $$
    O(n)
    $$
### 代码
```cpp
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int g2(int a){
    string tmp=std::to_string(a);//整数转换为字符串
    std::sort(tmp.begin(),tmp.end());//字符串进行排序(按照acsii码)
    return std::stoi(tmp);//字符串转换为整数
}
int g1(int a){
    string tmp=std::to_string(a);
    std::sort(tmp.begin(),tmp.end());
    std::reverse(tmp.begin(),tmp.end());//排序后逆置字符串
    return std::stoi(tmp);
}
int f(int a){
    return g1(a)-g2(a);
}
int main(){
    int a;
    int k;
    cin>>a>>k;
    for(int i=0;i<k;i++){//迭代推导至第k项
        a=f(a);
    }
    cout<<a;
}

```