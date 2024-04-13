## 佛洛伊德最短路径算法 讲解 以及 C++实现
+   算法的特点：  
    弗洛伊德算法(Floyd)是解决任意两点间的最短路径的一种算法，可以正确处理有向图或有向图或负权（但不可存在负权回路)的最短路径问题，同时也被用于计算有向图的传递闭包。

+   算法的思路


通过Floyd计算图G=(V,E)中各个顶点的最短路径时，需要引入两个矩阵，矩阵S中的元素a\[i\]\[j\]表示顶点i(第i个顶点)到顶点j(第j个顶点)的距离。矩阵P中的元素b\[i\]\[j\]，表示顶点i到顶点j经过了b\[i\]\[j\]记录的值所表示的顶点。

假设图G中顶点个数为N，则需要对矩阵D和矩阵P进行N次更新。初始时，矩阵D中顶点a\[i\]\[j\]的距离为顶点i到顶点j的权值；如果i和j不相邻，则a\[i\]\[j\]=∞，矩阵P的值为顶点b\[i\]\[j\]的j的值。 接下来开始，对矩阵D进行N次更新。第1次更新时，如果”a\[i\]\[j\]的距离” > “a\[i\]\[0\]+a\[0\]\[j\]”(a\[i\]\[0\]+a\[0\]\[j\]表示”i与j之间经过第1个顶点的距离”)，则更新a\[i\]\[j\]为”a\[i\]\[0\]+a\[0\]\[j\]”,更新b\[i\]\[j\]=b\[i\]\[0\]。 同理，第k次更新时，如果”a\[i\]\[j\]的距离” > “a\[i\]\[k-1\]+a\[k-1\]\[j\]”，则更新a\[i\]\[j\]为”a\[i\]\[k-1\]+a\[k-1\]\[j\]”,b\[i\]\[j\]=b\[i\]\[k-1\]。

#### 涉及到了两个矩阵
- 距离矩阵
  - 比较好理解，存储的是任意两点之间的最小距离
- 路径矩阵
  - 路径矩阵的第i行j列代表的时顶点i与顶点j之间最短距离的中间节点。
  - 例如i,j两个点
    -  最短的边为i-j，则路径矩阵的path[i][j]=i
    -  最短的边为i-k-j，则path[i][j]=k,path[i][k]=i;
    -  最短的边为i-k-h-j，则path[i][j]=h,path[i][h]=k,path[i][k]=i;
  - **在实现对应的路径输出时进行寻路输出**
### 3、Floyd算法的实例过程
![这里写图片描述](https://img-blog.csdn.net/20170311152309038?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

第一步，我们先初始化两个矩阵，得到下图两个矩阵：  
![这里写图片描述](https://img-blog.csdn.net/20170311153525086?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

、![这里写图片描述](https://img-blog.csdn.net/20170311154750742?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

第二步，以v1为中阶，更新两个矩阵：  
发现，a\[1\]\[0\]+a\[0\]\[6\] < a\[1\]\[6\] 和a\[6\]\[0\]+a\[0\]\[1\] < a\[6\]\[1\]，所以我们只需要矩阵D和矩阵P，结果如下：

![这里写图片描述](https://img-blog.csdn.net/20170311155027561?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

![这里写图片描述](https://img-blog.csdn.net/20170311155043212?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

通过矩阵P，我发现v2–v7的最短路径是：v2–v1–v7

第三步：以v2作为中介，来更新我们的两个矩阵，使用同样的原理，扫描整个矩阵，得到如下图的结果：

![这里写图片描述](https://img-blog.csdn.net/20170311155759700?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)  
![这里写图片描述](https://img-blog.csdn.net/20170311155812039?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

- 总结
> FLoyd算法其实就是每次选择一个中介点，更新根据这个中节点可以连接起来的两个点的距离信息，在path中记录对应的路径

### 代码
> **代码设计了一个FloydWay类，实现了有向图和无向图的两种版本**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int INF=1e6;
//
class FloydWay{
    public:
    int vertex_num;
    void out_matrix(vector<vector<int>>&matrix)const{
        for(int i=0;i<matrix.size();i++){
            for(int u=0;u<matrix[i].size();u++){
                if(matrix[i][u]==INF||matrix[i][u]==-1){
                    cout<<left<<setw(5)<<"/";
                }else{
                    cout<<left<<setw(5)<<matrix[i][u];
                }
            }
            cout<<endl;
        }
    }
    void out_path_single(int i,int u){
        int k=u;
        cout<<k<<"->";
        while(k!=i){
            k=path_matrix[i][k];
            cout<<k;
            if(k!=i){
                cout<<"->";
                continue;
            }else{
                cout<<" | min dist: "<<min_dist_matirx[i][u];
                cout<<endl;
            }
        }
    }
    void out_all_path(){
        for(int i=0;i<vertex_num;i++){
            for(int u=i+1;u<vertex_num;u++){
                cout<<i<<"-"<<u<<": ";
                out_path_single(i,u);
            }
        }
    }
    vector<vector<int>>graph_matrix;//图矩阵
    vector<vector<int>>min_dist_matirx;//最短距离矩阵
    vector<vector<int>>path_matrix;//路径矩阵
    FloydWay(vector<vector<int>>graph_matri):graph_matrix(graph_matri),vertex_num(graph_matri.size()){
        //初始化最短距离矩阵,路径矩阵
        min_dist_matirx=vector<vector<int>>(vertex_num,vector<int>(vertex_num,INF));
        path_matrix=vector<vector<int>>(vertex_num,vector<int>(vertex_num,-1));
        for(int i=0;i<vertex_num;i++){
            for(int j=0;j<vertex_num;j++){
                min_dist_matirx[i][j]=graph_matrix[i][j];
                path_matrix[i][j]=i;
            }
        }
    }
    void floyd_undirected(){//在无向图中的算法
        for(int i=0;i<vertex_num;i++){//第一层循环选择中间点
            for(int u=0;u<vertex_num;u++){//第二、三曾循环遍历顶点
                for(int k=0;k<vertex_num;k++){
                    if(min_dist_matirx[u][k]>min_dist_matirx[i][u]+min_dist_matirx[i][k]){
                        min_dist_matirx[u][k]=min_dist_matirx[i][u]+min_dist_matirx[i][k];
                        min_dist_matirx[k][u]=min_dist_matirx[i][u]+min_dist_matirx[i][k];
                        path_matrix[u][k]=i;
                        path_matrix[k][u]=i;
                    }
                }
            }
        }
        out_matrix(min_dist_matirx);
        out_matrix(path_matrix);
        out_all_path();
    }
    void floyd_directed(){//在有向图中的算法
        for(int i=0;i<vertex_num;i++){//第一层循环选择中间点
            for(int u=0;u<vertex_num;u++){//第二、三曾循环遍历顶点
                for(int k=0;k<vertex_num;k++){
                    if(min_dist_matirx[u][k]>min_dist_matirx[u][i]+min_dist_matirx[i][k]){
                        min_dist_matirx[u][k]=min_dist_matirx[u][i]+min_dist_matirx[i][k];
                        path_matrix[u][k]=i;
                    }
                }
            }
        }
        out_matrix(min_dist_matirx);
        out_matrix(path_matrix);
        out_all_path();
    }
};
int main(){
    vector<vector<int>>graph_undirected={//有向图
        {INF, 1, 4, INF},
        {1, INF, INF, 1},
        {4, INF, INF, 1},
        {INF, 1, 1, INF}
    };
    vector<vector<int>>graph_directed={//无向图
        {INF, 1, 4, INF},
        {INF, INF, INF, 1},
        {INF, INF, INF, INF},
        {INF, INF, 1, INF}
    };
    FloydWay(graph_undirected).floyd_undirected();
    FloydWay(graph_directed).floyd_directed();
}
```