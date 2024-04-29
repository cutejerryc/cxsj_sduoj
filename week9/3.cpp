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
    Deal().solve();
}