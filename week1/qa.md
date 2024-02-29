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
### 使用C++ freopen()函数实现重定向
- 文件输入
  ```cpp
  #include<iostream>
  #include<string>
  #include<stdio.h>
  using namespace std;
  int main(){
    string s;
    /*读取文件*/
    freopen("in.txt","r",stdin);//将输入流重定向到文件in.txt
    cin>>s;
    cout<<s<<endl;
    // 将输入流重定向到键盘输入
    freopen("/dev/tty", "r", stdin);
    /*写入文件*/
    cin>>s;
    //将输出流重定向到out.txt文件
    freopen("out.txt","w",stdout);
    cout<<s;
  }
  ```