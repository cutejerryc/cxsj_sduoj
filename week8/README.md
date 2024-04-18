# 山东大学程序设计思维与实践作业-Week8
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
### 解法
- 首先声明一个数组`arr`用于记录两个人在广场的时间节点，存储方式为
  - 如果小H在广场的时间段为`[a,b]`，则`arr[a]+=1`,`arr[b]+=-1`，小W同理
- 对数组进行更新，更新为`a[n]`即为数组`a`的前n项和
- 如果数组的某一项为2，则说明这一项对应的时间两人可以聊天
### 时间复杂度
$$
O(1)
$$
- 解释
  - 根据两人的时间段更新arr数组操作2*n次，n的最大值为2000，最多操作4000次
  - 遍历arr求n项和的时间复杂度最大为执行1000000次
  - 遍历arr求可以聊天的时间段最大为执行1000000次
  - 所以时间复杂度最大为 O(1000000)=O(1)
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n;
    vector<pair<int,int>>h,w;
    int max_h,max_w,max_t;
    int d[1000002]={0};
    Deal(){
        cin>>n;
        int a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            h.push_back(make_pair(a,b));
        }
        for(int i=0;i<n;i++){
            cin>>a>>b;
            w.push_back(make_pair(a,b));
        }
        max_h=h[h.size()-1].second;
        max_w=w[w.size()-1].second;
        max_t=max(max_h,max_w);
    }
    void solve(){
        for(int i=0;i<h.size();i++){
            d[h[i].first]+=1;
            d[h[i].second]-=1;
        }
        for(int i=0;i<w.size();i++){
            d[w[i].first]+=1;
            d[w[i].second]-=1;
        }
        int t=0;
        for(int i=1;i<=max_t;i++){
            t+=d[i];
            d[i]=t;
        }
        int time=0;
        for(int i=1;i<=max_t;i++){
            time+=(d[i]==2);
        }
        cout<<time<<endl;
    }
};
int main(){
    Deal().solve();
}
```
## 2
### 解法
- 该问题可以转换为判断图中是否存在负权环
- 利用Floyd算法计算所有点到所有点的最小距离
### 时间复杂度
$$
O(n^3)
$$
- 为Floyd算法的时间复杂度
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
//
class FloydWay{
    public:
    int vertex_num;
    vector<vector<int>>graph_matrix;//图矩阵
    vector<vector<int>>min_dist_matirx;//最短距离矩阵
    vector<vector<int>>path_matrix;//路径矩阵
    FloydWay(){
        //初始化最短距离矩阵,路径矩阵
        int m,w;
        cin>>vertex_num>>m>>w;
        graph_matrix=vector<vector<int>>(vertex_num+1,vector<int>(vertex_num+1,INF));
        min_dist_matirx=vector<vector<int>>(vertex_num+1,vector<int>(vertex_num+1,INF));
        path_matrix=vector<vector<int>>(vertex_num+1,vector<int>(vertex_num+1,-1));
        int a,b,d;
        for(int i=0;i<m;i++){
            cin>>a>>b>>d;
            graph_matrix[a][b]=d;
            graph_matrix[b][a]=d;
        }
        for(int i=0;i<w;i++){
            cin>>a>>b>>d;
            graph_matrix[a][b]=-d;
        }
        for(int i=1;i<=vertex_num;i++){
            for(int j=1;j<=vertex_num;j++){
                min_dist_matirx[i][j]=graph_matrix[i][j];
                path_matrix[i][j]=i;
            }
        }
    }
    void floyd_directed(){
        for(int i=1;i<=vertex_num;i++){//第一层循环选择中间点
            for(int u=1;u<=vertex_num;u++){//第二、三曾循环遍历顶点
                for(int k=1;k<=vertex_num;k++){
                    if(min_dist_matirx[u][k]>min_dist_matirx[u][i]+min_dist_matirx[i][k]){
                        min_dist_matirx[u][k]=min_dist_matirx[u][i]+min_dist_matirx[i][k];
                        path_matrix[u][k]=i;
                    }
                }
            }
        }
    }
    void judge_if_circle(){
        floyd_directed();
        for(int i=1;i<=vertex_num;i++){
            if(min_dist_matirx[i][i]<0){
                cout<<"YES"<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
    }
};
class Deal{
    public:
    int f;
    Deal(){
        cin>>f;
    }
    void solve(){
        for(int i=0;i<f;i++){
            FloydWay().judge_if_circle();
        }
    }
};
int main(){
    Deal().solve();
}
```