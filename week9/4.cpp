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