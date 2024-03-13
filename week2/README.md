# 山东大学程序设计思维与实践作业-Week2
**仅作参考，切莫照搬，有查重**
- 代码题目
  - 1
  ```shell
  git clone https://github.com/W1412X/cxsj_sduoj.git
  ```
  - 2  
前往https://github.com/W1412X/cxsj_sduoj.git获取

- 简答题目
## 1
### f1
- set使用红黑树实现，对应的insert()函数的时间复杂度是 log(n),所以整体的时间复杂度为:
$$
O(n\log(n))
$$
### f2
- O(n)
## 2
- sort函数的时间复杂度为O(nlogn),所以整体的时间复杂度为
$$
O(n\log(n))
$$
## 3
- sort函数中的迭代器要求是随机访问迭代器，但是list由双向链表实现，不支持随机存取
## 4
- std:find
  -std:find函数是顺序查找，对n个元素，其查找的时间复杂度为$$ O(n) $$
- map,set
  - 两者均基于红黑树实现，两者的find的函数相比于std:find有更好的性能，时间复杂度为
  $$ 
  \log(n) 
  $$
## 5
- 首先需要自定义比较函数来改变set的自动排序顺序
- 之后直接使用迭代器输出即可
```cpp
#include<bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(const int&a,const int&b)const{
        return a>b;
    }
};
int main(){
    set<int,Compare>a;
    for(int i=0;i<10;i++){
        a.insert(i);
    }
    set<int>::iterator it=a.begin();
    while(it!=a.end()){
        cout<<*it<<' ';
        it++;
    }
}
```
## 6
- 解法
  - 使用数组与优先队列解决此问题，数组的每个元素均为一个优先队列，用于模拟对应的桶
  - 将各个桶的元素放到对应的优先队列中
  - 最后遍历数组，从优先队列弹出元素
- 时间复杂度
$$
O(n+m\log(n))
$$
  - 解释
    - 创建大小为 n+1 的 vector为O(n)
    - 对于 m 次输入操作，每次插入操作的时间复杂度为 O(log n)，总为O(mlog(n))
    - 对于输出，pop的时间复杂度也为log(n),则对应的复杂度为O(mlog(n))

- 代码
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<priority_queue<int,vector<int>,greater<int>>>a(n+1,priority_queue<int,vector<int>,greater<int>>());//创建对应的优先级队列数组
    int p,q;
    for(int i=0;i<m;i++){
        cin>>p>>q;
        a[q].push(p);//将q桶的元素放入a[q]对应的堆中
    }
    for(int i=1;i<a.size();i++){
        while(a[i].size()>0){//对每一个桶，输出
            cout<<a[i].top()<<' ';
            a[i].pop();
        }
        cout<<endl;
    }
}
```
## 7
- 解法
  - 利用set的特性，在插入元素时自动按照字典序排列
  - 分别定义操作1-3
  - 根据每一行首个字符的不同进行操作
- 时间复杂度
  - 
  $$
  O(n\log(n))
  $$
  - 解释
   - 查找,插入，删除操作的时间复杂度为log(n)
   - 按照字典序输出的操作使用迭代器完成，时间复杂度为O(n)

- 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
set<string>s;//利用set可以自动按照字典序排列
void op1(string str){//查找单词的函数
    if(s.find(str)!=s.end()){
        cout<<"found"<<endl;
    }else{
        cout<<"write"<<endl;
        s.insert(str);
    }
}
void op2(string str){//删除单词的操作
    if(s.find(str)!=s.end()){
        cout<<"erased"<<endl;
        s.erase(str);
    }else{
        cout<<"not found"<<endl;
    }
}
void op3(){//按字典序通读笔记本
    
    for(const auto&e:s){
        cout<<e<<' ';
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    char op;
    string opstr;
    for(int i=0;i<n;i++){
        cin>>op;
        switch (op)
        {
        case '1'://查找
            cin>>opstr;
            op1(opstr);
            break;
        case '2'://删除
            cin>>opstr;
            op2(opstr);
            break;
        case '3'://通读
            op3();
            break;
        default:
            break;
        }
    }
}
```