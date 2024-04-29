#include<bits/stdc++.h>
using namespace std;
class Vertex{
    public:
    int id;
    bool if_visit=false;
    vector<float>fee;
    vector<float>happy;
    vector<int>can_go;
    Vertex(const int&i):id(i){if_visit=false;}
};
class DFS{
    public:
    int vertex_num;
    vector<Vertex>vertex_set;
    vector<bool>gone_vertex;
    vector<pair<int,pair<float,float>>>pre_msg;
    float max_=0;
    void init(){
        for(int i=0;i<vertex_set.size();i++){
            vertex_set[i].if_visit=false;
        }
        for(int i=0;i<gone_vertex.size();i++){
            gone_vertex[i]=false;
        }
    }
    DFS(){
        cin>>vertex_num;
        for(int i=0;i<vertex_num;i++){
            vertex_set.push_back(Vertex(i+1));
        }
        gone_vertex=vector<bool>(vertex_num+1,false);
        int m;
        cin>>m;
        int a,b,f,h;
        for(int i=0;i<m;i++){
            cin>>a>>b>>h>>f;
            vertex_set[a-1].can_go.push_back(b);
            vertex_set[a-1].fee.push_back(f);
            vertex_set[a-1].happy.push_back(h);
        }
    }
    void dfs(int id){
        for(int i=0;i<vertex_set[id-1].can_go.size();i++){
            pre_msg.push_back(make_pair(id,make_pair(vertex_set[id-1].fee[i],vertex_set[id-1].happy[i])));
            if(vertex_set[vertex_set[id-1].can_go[i]-1].if_visit){
                float sum_f=0,sum_h=0;
                for(int u=pre_msg.size()-1;u>=0;u--){
                    sum_f+=pre_msg[u].second.first;
                    sum_h+=pre_msg[u].second.second;
                    if(pre_msg[u].first==vertex_set[id-1].can_go[i]){
                        break;
                    }
                }
                float ans=sum_h/sum_f;
                if(ans>=max_){
                    max_=ans;
                }
            }
            vertex_set[vertex_set[id-1].can_go[i]-1].if_visit=true;
            if(!gone_vertex[vertex_set[id-1].can_go[i]]){
                gone_vertex[vertex_set[id-1].can_go[i]]=true;
                dfs(vertex_set[id-1].can_go[i]);
            }
            pre_msg.pop_back();
            vertex_set[vertex_set[id-1].can_go[i]-1].if_visit=false;
        }
    }
};
class Deal{
    public:
    Deal(){}
    void solve(){
        DFS d=DFS();
        for(int i=0;i<d.vertex_num;i++){
            d.init();
            d.vertex_set[i].if_visit=true;
            d.gone_vertex[i+1]=true;
            d.dfs(i+1);
        }
        cout << fixed << setprecision(1)<<d.max_;
    }
};
int main(){
    Deal().solve();
}