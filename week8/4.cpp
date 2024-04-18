#include<bits/stdc++.h>
using namespace std;
const long long int INF=1e10;
class Vertex{
    public:
    long long int id;
    long long int val;//这个val用于优先队列
    vector<pair<long long int,long long int>>can_go_vertex;
    Vertex(const long long int&i):id(i){};
    Vertex(const long long int&i,const long long int&v):id(i),val(v){};
    Vertex(){};
};
struct CompareVertex{
       bool operator()(const Vertex&thi,const Vertex&other){
        return thi.val>other.val;
    } 
};
class Dijksra{
    public:
    long long int vertex_num;
    vector<Vertex>vertex_set;
    vector<Vertex>vertex_set_inv;
    Dijksra(){

        long long int m;
        cin>>vertex_num>>m;
        long long int a,b,d;
        for(long long int i=0;i<=vertex_num;i++){
            vertex_set.push_back(Vertex(i,INF));
            vertex_set_inv.push_back(Vertex(i,INF));
        }
        vertex_set[1].val=0;
        vertex_set_inv[1].val=0;
        for(long long int i=0;i<m;i++){
            cin>>a>>b>>d;
            vertex_set[a].can_go_vertex.push_back(make_pair(b,d));
            vertex_set_inv[b].can_go_vertex.push_back(make_pair(a,d));
        }
    }
    long long int dijksra(vector<Vertex>&vertex_set){
        bool if_in[1000010]={false};
        priority_queue<Vertex ,vector<Vertex >,CompareVertex>pq;
        pq.push(vertex_set[1]);
        while(!pq.empty()){
            Vertex tmp=pq.top();
            pq.pop();
            if(if_in[tmp.id]){
                continue;
            }
            if_in[tmp.id]=1;
            for(long long int i=0;i<tmp.can_go_vertex.size();i++){
                if(tmp.val+tmp.can_go_vertex[i].second<vertex_set[tmp.can_go_vertex[i].first].val){
                    vertex_set[tmp.can_go_vertex[i].first].val=tmp.val+tmp.can_go_vertex[i].second;
                    pq.push(vertex_set[tmp.can_go_vertex[i].first]);
                }
            }
        }
        long long int sum=0;
        for(long long int i=2;i<=vertex_num;i++){
            sum+=vertex_set[i].val;
        }
        return sum;
    }
    long long int all_sum(){
        return dijksra(vertex_set)+dijksra(vertex_set_inv);
    }
};
class Deal{
    public:
    long long int t;
    Deal(){
        cin>>t;
    }
    void solve(){
        for(long long int i=0;i<t;i++){
            cout<<Dijksra().all_sum()<<endl;
        }
    }
};
int main(){
    Deal().solve();
}