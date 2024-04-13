# ## SFPA最短路径算法 讲解 以及 C++实现
### 1、最短路径问题介绍

问题解释：  
从图中的某个顶点出发到达另外一个顶点的所经过的边的权重和最小的一条路径，称为最短路径

解决问题的算法：
+   **SFPA算法**
+   [迪杰斯特拉算法（Dijkstra算法）]()
+   [弗洛伊德算法（Floyd算法）](https://blog.csdn.net/m0_73802120/article/details/137697063?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22137697063%22%2C%22source%22%3A%22m0_73802120%22%7D)
### 2、SPFA算法介绍

SPFA算法是求解单源最短路径问题的一种算法，由理查德·贝尔曼（Richard Bellman） 和 莱斯特·福特 创立的。有时候这种算法也被称为 Moore-Bellman-Ford 算法，因为 Edward F. Moore 也为这个算法的发展做出了贡献。它的原理是对图进行V-1次松弛操作，得到所有可能的最短路径。**其优于迪科斯彻算法的方面是边的权值可以为负数、实现简单，缺点是时间复杂度过高，高达 O(VE)。但算法可以进行若干种优化，提高了效率。**

算法的思路：  
我们用数组dis记录每个结点的最短路径估计值，用邻接表或邻接矩阵来存储图G。我们采取的方法是动态逼近法：设立一个先进先出的队列用来保存待优化的结点，优化时每次取出队首结点u，并且用u点当前的最短路径估计值对离开u点所指向的结点v进行松弛操作，如果v点的最短路径估计值有所调整，且v点不在当前的队列中，就将v点放入队尾。这样不断从队列中取出结点来进行松弛操作，直至队列空为止

#### 判断存在负环的方法

1.  开始算法前，调用拓扑排序进行判断（一般不采用，浪费时间）
2.  如果某个点进入队列的次数超过N次则存在负环（N为图的顶点数）

### 3、SPFA算法手动操作过程

下面我们采用SPFA算法对下图求v1到各个顶点的最短路径，通过手动的方式来模拟SPFA每个步骤的过程

![这里写图片描述](https://img-blog.csdn.net/20170312100750154?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

+   **初始化：**

首先我们先初始化数组dis如下图所示：（除了起点赋值为0外，其他顶点的对应的dis的值都赋予无穷大，这样有利于后续的松弛）  
![这里写图片描述](https://img-blog.csdn.net/20170312101152077?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

此时，我们还要把v1如队列：{v1}

现在进入循环，直到队列为空才退出循环。

+   第一次循环：

首先，队首元素出队列，即是v1出队列，然后，对以v1为弧尾的边对应的弧头顶点进行松弛操作，可以发现v1到v3，v5，v6三个顶点的最短路径变短了，更新dis数组的值，得到如下结果：  
![这里写图片描述](https://img-blog.csdn.net/20170312101824596?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

我们发现v3，v5，v6都被松弛了，而且不在队列中，所以要他们都加入到队列中：{v3，v5，v6}

+   第二次循环

此时，队首元素为v3，v3出队列，然后，对以v3为弧尾的边对应的弧头顶点进行松弛操作，可以发现v1到v4的边，经过v3松弛变短了，所以更新dis数组，得到如下结果：  
![这里写图片描述](https://img-blog.csdn.net/20170312102841379?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

此时只有v4对应的值被更新了，而且v4不在队列中，则把它加入到队列中：{v5,v6,v4}

+   第三次循环

此时，队首元素为v5，v5出队列，然后，对以v5为弧尾的边对应的弧头顶点进行松弛操作，发现v1到v4和v6的最短路径，经过v5的松弛都变短了，更新dis的数组，得到如下结果：  
![这里写图片描述](https://img-blog.csdn.net/20170312103146586?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

我们发现v4、v6对应的值都被更新了，但是他们都在队列中了，所以不用对队列做任何操作。队列值为：{v6，v4}

+   第四次循环  
    此时，队首元素为v6，v6出队列，然后，对以v6为弧尾的边对应的弧头顶点进行松弛操作，发现v6出度为0，所以我们不用对dis数组做任何操作，其结果和上图一样，队列同样不用做任何操作，它的值为：{v4}
    
+   第五次循环  
    此时，队首元素为v4，v4出队列，然后，对以v4为弧尾的边对应的弧头顶点进行松弛操作，可以发现v1到v6的最短路径，经过v4松弛变短了，所以更新dis数组，得到如下结果：  
    ![这里写图片描述](https://img-blog.csdn.net/20170312103601015?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
    

因为我修改了v6对应的值，而且v6也不在队列中，所以我们把v6加入队列，{v6}

+   第六次循环  
    此时，队首元素为v6，v6出队列，然后，对以v6为弧尾的边对应的弧头顶点进行松弛操作，发现v6出度为0，所以我们不用对dis数组做任何操作，其结果和上图一样，队列同样不用做任何操作。所以此时队列为空。

OK，队列循环结果，此时我们也得到了v1到各个顶点的最短路径的值了，它就是dis数组各个顶点对应的值，如下图：  
![这里写图片描述](https://img-blog.csdn.net/20170312103827419?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMzU2NDQyMzQ=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

### 4、SPFA算法的代码实现
> 定义了一个SpfaWay类
```cpp
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
    SpfaWay(vector<vector<int>>a,int target_verte):graph_matrix(a),vertex_num(graph_matrix.size()),target_vertex(target_verte){//
        min_dist_set=vector<int>(vertex_num,INF);
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
        for(int i=0;i<vertex_num;i++){
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
    void spfa(){
        push(target_vertex);
        while(!q.empty()){
            int vertex_now=q.front();
            pop();
            for(int i=0;i<vertex_num;i++){
                if(min_dist_set[i]>graph_matrix[target_vertex][vertex_now]+graph_matrix[vertex_now][i]){
                    min_dist_set[i]=graph_matrix[target_vertex][vertex_now]+graph_matrix[vertex_now][i];
                    path_record[i]=vertex_now;
                    if(!if_in_queue[i]){//判段这个点是否在队列内，如果不在就加入
                        push(i);
                        if(vertex_record_times[i]>vertex_num){//判断负权环的存在
                            cout<<"存在负权环"<<endl;
                            return;
                        }
                    }
                }
            }
        }
        out_path_all();
    }
};
int main(){
    vector<vector<int>>graph_directed={
        {0, 1, 4, INF},
        {INF, 0, INF, 1},
        {INF, INF, 0, INF},
        {INF, INF, 1, 0}
    };
    SpfaWay(graph_directed,0).spfa();
}
```