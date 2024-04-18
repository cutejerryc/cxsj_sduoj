#include<bits/stdc++.h>
using namespace std;
const long long int INF=1e12;
class Vertex{
    public:
    long long int id;
    long long int t;//
    vector<pair<long long int,pair<long long int,long long int>>>can_go_vertex;
    Vertex(const long long int&i):id(i){};
    Vertex(const long long int&i,const long long int&v):id(i),t(v){};
    Vertex(){};
};
struct CompareVertex{
       bool operator()(const Vertex&thi,const Vertex&other){
        return thi.t>other.t;
    } 
};
class Dijksra{
    public:
    long long int vertex_num;
    long long int limit_weight;
    vector<Vertex>vertex_set;
    Dijksra(const long long int&vn,const long long int&lw,const vector<Vertex>&vs){
        vertex_num=vn;
        limit_weight=lw;
        vertex_set=vs;
    }
    long long int dijksra(){
        bool if_in[10010]={false};
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
                if(tmp.t+tmp.can_go_vertex[i].second.second<vertex_set[tmp.can_go_vertex[i].first].t&&tmp.can_go_vertex[i].second.first>=limit_weight){
                    vertex_set[tmp.can_go_vertex[i].first].t=tmp.t+tmp.can_go_vertex[i].second.second;
                    pq.push(vertex_set[tmp.can_go_vertex[i].first]);
                }
            }
        }
        return vertex_set[vertex_num].t;
    }
};
class Deal{
    public:
    long long int x;
    Deal(){
        cin>>x;
    }
    void solve(){
        long long int n,m,limit_t;
        long long int a,b,c,d;
        for(long long int i=0;i<x;i++){
            cin>>n>>m>>limit_t;
            vector<Vertex>vertex_set;
            for(long long int i=0;i<n+1;i++){
                vertex_set.push_back(Vertex(i,INF));
            }
            vertex_set[1].t=0;
            vector<long long int>weight_set;
            for(long long int i=0;i<m;i++){
                cin>>a>>b>>c>>d;
                vertex_set[a].can_go_vertex.push_back(make_pair(b,make_pair(c,d)));
                vertex_set[b].can_go_vertex.push_back(make_pair(a,make_pair(c,d)));
                weight_set.push_back(c);
            }
            sort(weight_set.begin(),weight_set.end());
            long long int l=0;
            long long int r=weight_set.size()-1;
            while(r-l>1){
                long long int mid=(r+l)/2;
                long long int t=Dijksra(vertex_set.size()-1,weight_set[mid],vertex_set).dijksra();
                if(t<limit_t){
                    l=mid;
                }else{
                    r=mid;
                }
            }
            cout<<weight_set[l]<<endl;
        }
    }
};
int main(){
    Deal().solve();
}