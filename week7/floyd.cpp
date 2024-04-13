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
        cout<<k<<"<-";
        while(k!=i){
            k=path_matrix[i][k];
            cout<<k;
            if(k!=i){
                cout<<"<-";
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
        cout<<"初始的距离矩阵"<<endl;
        out_matrix(min_dist_matirx);
        cout<<"初始的路径矩阵"<<endl;
        out_matrix(path_matrix);
    }
    void floyd_undirected(){//在无向图中的算法
    cout<<"###无向图###"<<endl;
        for(int i=0;i<vertex_num;i++){//第一层循环选择中间点
            for(int u=0;u<vertex_num;u++){//第二、三曾循环遍历顶点
                for(int k=0;k<vertex_num;k++){
                    if(min_dist_matirx[u][k]>min_dist_matirx[i][u]+min_dist_matirx[i][k]){
                        min_dist_matirx[u][k]=min_dist_matirx[i][u]+min_dist_matirx[i][k];
                        min_dist_matirx[k][u]=min_dist_matirx[i][u]+min_dist_matirx[i][k];
                        path_matrix[u][k]=i;
                        path_matrix[k][u]=i;
                        cout<<u<<"到"<<k<<"(双向)以"<<i<<"为中间节点可以取得更小值"<<endl;
                        cout<<"更新后的距离矩阵："<<endl;
                        out_matrix(min_dist_matirx);
                        cout<<"更新后的路径矩阵："<<endl;
                        out_matrix(path_matrix);
                    }
                }
            }
        }
        cout<<"最终的距离矩阵："<<endl;
        out_matrix(min_dist_matirx);
        cout<<"最终的路径矩阵："<<endl;
        out_matrix(path_matrix);
        out_all_path();
    }
    void floyd_directed(){//在有向图中的算法
        cout<<"###有向图###"<<endl;
        for(int i=0;i<vertex_num;i++){//第一层循环选择中间点
            for(int u=0;u<vertex_num;u++){//第二、三曾循环遍历顶点
                for(int k=0;k<vertex_num;k++){
                    if(min_dist_matirx[u][k]>min_dist_matirx[u][i]+min_dist_matirx[i][k]){
                        min_dist_matirx[u][k]=min_dist_matirx[u][i]+min_dist_matirx[i][k];
                        path_matrix[u][k]=i;
                        cout<<u<<"到"<<k<<"(单向)以"<<i<<"为中间节点可以取得更小值"<<endl;
                        cout<<"更新后的距离矩阵："<<endl;
                        out_matrix(min_dist_matirx);
                        cout<<"更新后的路径矩阵："<<endl;
                        out_matrix(path_matrix);
                    }
                }
            }
        }
        cout<<"最终的距离矩阵："<<endl;
        out_matrix(min_dist_matirx);
        cout<<"最终的路径矩阵："<<endl;
        out_matrix(path_matrix);
        out_all_path();
    }
};
int main(){
    vector<vector<int>>graph_undirected={
        {0, 1, 4, INF},
        {1, 0, INF, 1},
        {4, INF, 0, 1},
        {INF, 1, 1, 0}
    };
    vector<vector<int>>graph_directed={
        {0, 1, 4, INF},
        {INF, 0, INF, 1},
        {INF, INF, 0, INF},
        {INF, INF, 1, 0}
    };
    FloydWay(graph_undirected).floyd_undirected();
    FloydWay(graph_directed).floyd_directed();
}