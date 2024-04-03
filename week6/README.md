# 山东大学程序设计思维与实践作业-Week5
**仅作参考，切莫照搬，有查重**
# 代码题目
  - 1
  ```shell
  git clone https://github.com/W1412X/cxsj_sduoj.git
  ```
  - 2  
前往[点击此处](https://github.com/W1412X/cxsj_sduoj.git)获取

# 简答题目
## 1
### 邻接表
- 
  - 是一种链式存储结构，表示顶点到顶点的关系集合
- 优点
  - 节省空间，只需要存储存在的边，适用于稀疏矩阵
  - 易于在动态图中使用，删除节点添加节点方便
  - 易于处理带权图
- 缺点
  - 查询边是否存在比较慢
  - 对于稠密的图，效率低
### 邻接矩阵
- 
  - 二维数组表示顶点之间的连接关系
- 优点
  - 查询边是否存在快
  - 稠密图适用
- 缺点
  - 占用空间大
  - 对于带权图处理较为不便
## 2
- 过程
  - 将所有的边按照边权值从小到大排序
  - 依次取出边尝试放入图中
    - 若形成环，则将边舍弃
    - 反之继续循环
  - 直至边没了或者图中的边数=节点数-1
- 判断连通
  - 当前的图中的边数是否等于顶点数-1
## 3
### 解法
- 使用并查集实现获取一个连通图的代表元
- 为了减少重复计算以及查找，记录当前的非连通图的个数，每次使用并查集类合并时就减少一个
### 时间复杂度
$$
O(m\log(n))
$$
- 解释
  - 并查集采用了路径压缩，最坏情况下时间复杂度为O(log(n))
  - 一共进行m次合并查找操作  
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    int a[1000000];
    int element_num;
    int disjoint_sets_count;//记录互斥集合的数量
    DisjointSet(int n){
        element_num=n;
        disjoint_sets_count = n;//初始时每个元素都是一个不相交的集合
        for(int i=0;i<=n;i++){
            a[i]=i;
        }
    }
    DisjointSet(){}
    int find(int&index){
        if(a[index]==index){
            return index;
        }else{
            a[index]=find(a[index]);
            return a[index];
        }
    }
    int get_disjoinsets_count(){
        return disjoint_sets_count;//直接返回
    }
    bool combine(int&x,int&y){
        int root_x=find(x);
        int root_y=find(y);
        if(root_x==root_y){
            return false;
        }else{
            a[root_y]=root_x;
            disjoint_sets_count--;//合并后减少一个互斥集合
        }
        return true;
    }
};
class Deal{
    public:
    int n,m;
    DisjointSet ds;
    Deal(){
        cin>>n>>m;
        ds=DisjointSet(n);
    }
    void solve(){
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            ds.combine(a,b);
            cout<<ds.get_disjoinsets_count()-1<<endl;
        }
    }

};
int main(){
    Deal().solve();
}
```

## 4
### 解法
- 使用kruskral算法求解
- 特殊的由于 可以随意的在田地旁添加抽水机，则可以设置一种特殊的边
  - 这种边的权值为p，连接节点0与这个节点(节点0不再图内计算)
  - 由于最多可以全部使用抽水机，故向边集中添加n个这种边
### 时间复杂度
$$
O(nlog(n))
$$
- 解释
  - kruskal算法中涉及排序操作，对2n个元素排序，则时间复杂度为O(nlog(n))
  - 遍历尝试添加边最多进行2n次，时间复杂度为O(2n)
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    long long a[100000];
    long long element_num;
    DisjointSet(long long n){
        element_num=n;
        for(long long i=0;i<=n;i++){
            a[i]=i;
        }
    }
    DisjointSet(){}
    long long find(long long&index){
        if(a[index]==index){
            return index;
        }else{
            a[index]=find(a[index]);
            return a[index];
        }
    }
    long long get_disjoinsets_count(){
        long long re=0;
        unordered_map<long long,bool>m_;
        for(long long i=0;i<element_num;i++){
            if(m_.find(find(a[i]))==m_.end()){
                m_[a[i]]=true;
                re++;
            }
        }
        return re;
    }
    void combine(long long x,long long y){
        long long root_x=find(x);
        long long root_y=find(y);
        if(root_x==root_y){
            return;
        }else{
            a[root_y]=root_x;
        }
    }
};
class Edge{
    public:
    pair<long long,long long>points;
    long long val;
    Edge(long long p1,long long p2,long long v){
        points=make_pair(p1,p2);
        val=v;
    }
    Edge(){}
    bool operator <(const Edge&other){
        return this->val<other.val;
    }
};
class Deal{
    public:
    long long n,m,p;
    vector<Edge>edge_set;
    DisjointSet ds;
    Deal(){
        cin>>n>>m>>p;
        long long a,b,c;
        ds=DisjointSet(n);
        for(long long i=0;i<m;i++){
            cin>>a>>b>>c;
            edge_set.push_back(Edge(a,b,c));
        }
        for(int i=1;i<=n;i++){
            edge_set.push_back(Edge(0,i,p));
        }
    }
    pair<long long,long long> kruskal(long long edge_limit){
        long long count=0;
        long long re=p;
        sort(edge_set.begin(),edge_set.end());
        for(long long i=0;i<edge_set.size()&&count<edge_limit;i++){
            if(ds.find(edge_set[i].points.first)!=ds.find(edge_set[i].points.second)){
                re+=edge_set[i].val;
                ds.combine(edge_set[i].points.first,edge_set[i].points.second);
                count++;
            }
        }
        return make_pair(re,count);
    }
    void solve(){
        pair<long long,long long>pai_r=kruskal(m);
        cout<<pai_r.first+(n-pai_r.second-1)*p;
    }
};
int main(){
    Deal().solve();
}
```