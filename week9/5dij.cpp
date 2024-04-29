#include<bits/stdc++.h>
using namespace std;
class Val{
    public:
    float v,p;
    Val(const float&v_,const float&p_){
        v=v_;
        p=p_;
    }
    Val(){
        v=0;
        p=0;
    }
    float get_val(){
        if(p==0){
            return 0;
        }
        return v/p;
    }
};
class Vertex{
    public:
    Vertex(const int&i,const Val&md):id(i),max_dist(md){};
    int id;
    Val max_dist;
    vector<pair<int,Val>>cango;
};
vector<Vertex*>vertex_set;
vector<vector<int>>can_be_go;
struct CompareVertex{
       bool operator()(Vertex*thi,Vertex*other){
        return thi->max_dist.get_val()<other->max_dist.get_val();
    } 
};
class Dijksra{
    public:
    int vertex_num;
    Dijksra(int num):vertex_num(num){}
    float compute(float a,float b){
        if(b==0){
            return 0;
        }
        return a/b;
    }
    float dijskral(int start_id){
        bool if_in[2001]={false};
        priority_queue<Vertex*,vector<Vertex*>,CompareVertex>pq;
        pq.push(vertex_set[start_id]);
        while(!pq.empty()){
            Vertex* top=pq.top();
            pq.pop();
            if(if_in[top->id]){
                continue;
            }
            if_in[top->id]=1;
            for(int i=0;i<top->cango.size();i++){
                float intr=compute((top->max_dist.v+top->cango[i].second.v),(top->max_dist.p+top->cango[i].second.p));
                float to_go_dist=vertex_set[top->cango[i].first]->max_dist.get_val();
                if(to_go_dist<intr){
                    vertex_set[top->cango[i].first]->max_dist.v=(top->max_dist.v+top->cango[i].second.v);
                    vertex_set[top->cango[i].first]->max_dist.p=(top->max_dist.p+top->cango[i].second.p);
                    pq.push(vertex_set[top->cango[i].first]);
                }
            }
        }
        float max=vertex_set[start_id]->max_dist.get_val();
        /*for(int i:can_be_go[start_id]){
            float v_before=vertex_set[i]->max_dist.v;
            float p_before=vertex_set[i]->max_dist.p;
            float v_this=vertex_set[start_id]->max_dist.v;
            float p_this=vertex_set[start_id]->max_dist.p;
            float re=(v_before+v_this)/(p_before+p_this);
            if(max<re){
                max=re;
            }
        }*/
        return max;
    }
};
class Deal{
    public:
    int n;
    Deal(){
        int m;
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            Vertex*tmp=new Vertex(i,Val());
            vertex_set.push_back(tmp);
        }
        int a,b;
        float c,d;
        can_be_go=vector<vector<int>>(n+1,vector<int>(0));
        for(int i=0;i<m;i++){
            cin>>a>>b>>c>>d;
            vertex_set[a]->cango.push_back(make_pair(b,Val(c,d)));
            can_be_go[b].push_back(a);
        }
    }
    void init(){
        for(int i=0;i<=n;i++){
            vertex_set[i]->max_dist.p=0;
            vertex_set[i]->max_dist.v=0;
        }
    }
    void solve(){
        float max_=0;
        for(int i=1;i<=n;i++){
            init();
            Dijksra dij=Dijksra(n);
            float re=dij.dijskral(i); 
            max_=max(re,max_);  
        }
        cout<<fixed<<setprecision(1)<<max_<<endl;
    }
};
int main(){
    Deal().solve();
}