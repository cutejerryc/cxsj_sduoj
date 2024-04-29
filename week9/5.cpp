#include<bits/stdc++.h>
using namespace std;
const float INF=1e9;
//
class FloydWay{
    public:
    int vertex_num;
    vector<vector<pair<float,float>>>graph_matrix;//图矩阵
    vector<vector<float>>max_dist_set;//最短距离矩阵
    vector<vector<int>>path_matrix;//路径矩阵
    FloydWay(){
        //初始化最短距离矩阵,路径矩阵
        int m,w;
        cin>>vertex_num>>m;
        graph_matrix=vector<vector<pair<float,float>>>(vertex_num+1,vector<pair<float,float>>(vertex_num+1,make_pair(0,0)));
        max_dist_set=vector<vector<float>>(vertex_num+1,vector<float>(vertex_num+1,0));
        path_matrix=vector<vector<int>>(vertex_num+1,vector<int>(vertex_num+1,-1));
        int a,b,c,d;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c>>d;
            graph_matrix[a][b].first=c;
            graph_matrix[a][b].second=d;
        }
        for(int i=1;i<=vertex_num;i++){
            for(int j=1;j<=vertex_num;j++){
                max_dist_set[i][j]=0;
                path_matrix[i][j]=i;
            }
        }
    }
    float compute_intr(const float&a,const float&b){
        if(a==0&&b==0){
            return 0;
        }
        else{
            return a/b;
        }
    }
    void floyd_directed(){
        for(int i=1;i<=vertex_num;i++){//第一层循环选择中间点
            for(int u=1;u<=vertex_num;u++){//第二、三曾循环遍历顶点
                for(int k=1;k<=vertex_num;k++){
                    if(u==k){
                        continue;
                    }
                    if((graph_matrix[u][i].first==0&&u!=i)||(graph_matrix[i][k].first==0&&i!=k)){
                        continue;
                    }
                    float intr=compute_intr((graph_matrix[u][i].first+graph_matrix[i][k].first),(graph_matrix[u][i].second+graph_matrix[i][k].second));
                    if(max_dist_set[u][k]<intr){
                        max_dist_set[u][k]=intr;
                        int first=graph_matrix[u][i].first;
                        int second=graph_matrix[u][i].second;
                        graph_matrix[u][k].first=first+graph_matrix[i][k].first;
                        graph_matrix[u][k].second=second+graph_matrix[i][k].second;
                        path_matrix[u][k]=i;
                    }
                }
            }
        }
    }
    void judge_if_circle(){
        floyd_directed();
        for(int i=1;i<=vertex_num;i++){
            if(max_dist_set[i][i]<0){
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
    }
    void solve(){
        FloydWay fw=FloydWay();
        fw.floyd_directed();
        float max_=0;
        for(int i=1;i<fw.max_dist_set.size();i++){
            if(max_<fw.max_dist_set[i][i]){
                max_=fw.max_dist_set[i][i];
            }
        }
        cout<<max_<<'1'<<endl;
    }
};
int main(){
    Deal().solve();
}