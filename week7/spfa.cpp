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