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
- n个变量，在图中对应n个点，m个不等式，在图中对应m个边，采用Spfa算法（队列优化）的时间复杂度为
$$
O(n\cdot m)
$$
## 2
### 解法
- 利用差分约束转换不等式为边，对应五种转换为
  - k=1
  $$
  x_b<=x_a+c
  $$
  - k=2
  $$
  x_a<=x_b-c
  $$
  - k=3
  $$
  x_b<=x_a+c-1
  $$
  - k=4
  $$
  x_a<=x_b-c-1
  $$
  - k=5
  $$
  x_a<=x_b+c
  x_b<=x_a-c
  $$
- 然后用对应的Spfa算法带入即可
### 时间复杂度
- 
$$
O(n\cdot m)
$$
- 解释
  -n个变量，在图中对应n个点，m个不等式，在图中对应m个边，采用Spfa算法（队列优化）的时间复杂度为
$$
O(n\cdot m)
$$
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int INF=1e6;
class SpfaWay{
    public:
    queue<int>q;
    int target_vertex;
    vector<vector<int>>graph_matrix;//图的邻接矩阵
    int vertex_num;//顶点个数
    vector<int>min_dist_set;//每个顶点到目标顶点的最短距离
    vector<int>path_record=vector<int>(vertex_num,0);//记录路径
    vector<int>vertex_record_times=vector<int>(vertex_num,0);//记录每个顶点进入队列的次数
    vector<bool>if_in_queue=vector<bool>(vertex_num,false);//记录顶点当前是否在队列中
    SpfaWay(vector<vector<int>>a,int target_verte):graph_matrix(a),vertex_num(graph_matrix.size()-1),target_vertex(target_verte){//
        min_dist_set=vector<int>(vertex_num+1,INF);
        for(int i=0;i<vertex_num;i++){//初始化路径记录数组
            if(graph_matrix[target_vertex][i]==INF){
                path_record[i]=-1;
            }else{
                path_record[i]=target_vertex;
            }
        }
    }
    void out_path_single(int i){
        cout<<i;
        while(i!=target_vertex){
            cout<<"<-";
            i=path_record[i];
            cout<<i;
        }
        cout<<endl;
    }
    void out_path_all(){
        for(int i=0;i<=vertex_num;i++){
            out_path_single(i);
        }
    }
    void push(int i){
        q.push(i);
        vertex_record_times[i]++;
        if_in_queue[i]=true;
    }
    void pop(){
        if_in_queue[q.front()]=false;
        q.pop();
    }
    bool spfa(){
        push(target_vertex);
        min_dist_set[target_vertex]=0;
        while(!q.empty()){
            int vertex_now=q.front();
            pop();
            for(int i=0;i<=vertex_num;i++){
                if(graph_matrix[vertex_now][i]!=INF)
                if(min_dist_set[i]>min_dist_set[vertex_now]+graph_matrix[vertex_now][i]){
                    min_dist_set[i]=min_dist_set[vertex_now]+graph_matrix[vertex_now][i];
                    path_record[i]=vertex_now;
                    if(!if_in_queue[i]){//判段这个点是否在队列内，如果不在就加入
                        push(i);
                        if(vertex_record_times[i]>=vertex_num){//判断负权环的存在
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
class Deal{
    public:
    int n;
    vector<vector<int>>graph_directed;
    Deal(){
        cin>>n;
        for(int i=0;i<=n;i++){
            graph_directed.push_back(vector<int>(n+1,INF));
        }
        int m;
        cin>>m;
        int a,b,c,d;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c>>d;
            b=b-1;
            if (a == 1){
                graph_directed[b][c] = d;
            }
            else if (a == 2){
                graph_directed[c][b] = -d;
            }
            else if (a == 3){
                graph_directed[b][c] = d - 1;
            }
            else if (a == 4){
                graph_directed[c][b] = -d - 1;
            }
            else{
                graph_directed[b][c] = d;
                graph_directed[c][b] = -d;
            }
        }
        for(int i=0;i<=n-1;i++){//坑之间要么种要么不种,从0开始，0坑辅助1坑
            graph_directed[i][i+1]=1;
            graph_directed[i+1][i]=0;
        }
    }
    void solve(){
        SpfaWay sw=SpfaWay(graph_directed,0);
        bool re=sw.spfa();
        if(re)
        cout<<sw.min_dist_set[n]<<endl;
        else{
            cout<<"impossible"<<endl;
        }
    }
};
int main(){
    Deal d=Deal();
    d.solve();
}
```
## 3
### 解法
- 利用Tarjon找强连通分量，然后，将强连通分量视作一个点，重新建图，这道题只需要找出点的入度为0的数目
### 时间复杂度
- 
$$
O(n + m)
$$
- 解释
  - Tarjon算法的时间复杂度为O(n+m),后面重新建图我的代码的时间复杂度平均为O(n+m)
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class Vertex{
    public:
    int id;
    int visit_time;
    int erliest_time;
    vector<int>can_go;
    Vertex(const int&id_):id(id_),visit_time(-1){}
};
class Tarjon{
    public:
    int vertex_num;
    vector<Vertex>vertex_set;
    vector<vector<int>>scc_set;
    stack<int>sk;
    vector<bool>if_in_stack;
    vector<int>which_scc;
    vector<int>scc_in_degree;
    int time;
    Tarjon(){
        time=0;
        cin>>vertex_num;
        for(int i=0;i<=vertex_num;i++){
            vertex_set.push_back(Vertex(i));
            if_in_stack.push_back(false);
            which_scc.push_back(-1);
        }
        int m;
        cin>>m;
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            vertex_set[a].can_go.push_back(b);
        }
    }
    void tarjon(const int&id){
        vertex_set[id].visit_time=++time;
        vertex_set[id].erliest_time=vertex_set[id].visit_time;
        sk.push(id);
        if_in_stack[id]=true;
        for(int i:vertex_set[id].can_go){
            if(vertex_set[i].visit_time==-1){//没有访问过
                tarjon(i);
                vertex_set[id].erliest_time=min(vertex_set[id].erliest_time,vertex_set[i].erliest_time);
            }else if(if_in_stack[i]){//访问过而且在栈里，有环路
                vertex_set[id].erliest_time=min(vertex_set[id].erliest_time,vertex_set[i].visit_time);
            }
        }
        if(vertex_set[id].erliest_time==vertex_set[id].visit_time){
            scc_set.push_back(vector<int>(0));
            while(sk.top()!=id){
                which_scc[sk.top()]=scc_set.size();
                vertex_set[sk.top()].erliest_time=vertex_set[id].visit_time;
                scc_set[scc_set.size()-1].push_back(sk.top());
                if_in_stack[sk.top()]=false;
                sk.pop();
            }
            which_scc[id]=scc_set.size();
            scc_set[scc_set.size()-1].push_back(sk.top());
            if_in_stack[id]=false;
            sk.pop();
        }
    }
    void rebuild(){
        for(int i=0;i<scc_set.size();i++){
            scc_in_degree.push_back(0);
        }
        for(int i=0;i<scc_set.size();i++){
            Vertex v(i+1);
            for(int u=0;u<scc_set[i].size();u++){
                for(int k=0;k<vertex_set[scc_set[i][u]].can_go.size();k++){
                    int scc_id=which_scc[vertex_set[scc_set[i][u]].can_go[k]];
                    if(v.id!=scc_id){
                        //v.can_go.push_back(scc_id);//这个题目不用重构图，只需要记一下对应的度数
                        scc_in_degree[scc_id]++;
                    }
                }
            }
        }
    }
};
class Deal{
    public:
    Tarjon tj;
    Deal(){
    }
    void solve(){
        for(int i=1;i<=tj.vertex_num;i++){
            if(tj.vertex_set[i].visit_time==-1)
            tj.tarjon(i);
        }
        tj.rebuild();
        int re=0;
        for(int i=0;i<tj.scc_in_degree.size();i++){
            re+=(tj.scc_in_degree[i]==0);
        }
        cout<<re<<endl;
    }
};
int main(){
    Deal().solve();
}

```