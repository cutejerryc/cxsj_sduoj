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