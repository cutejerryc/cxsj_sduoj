#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    long long a[100000];
    long long element_num;
    DisjointSet(long long n){
        element_num=n;
        for(long long i=0;i<=n;i++){
            a[i]=i;
        }
    }
    DisjointSet(){}
    long long find(long long&index){
        if(a[index]==index){
            return index;
        }else{
            a[index]=find(a[index]);
            return a[index];
        }
    }
    long long get_disjoinsets_count(){
        long long re=0;
        unordered_map<long long,bool>m_;
        for(long long i=0;i<element_num;i++){
            if(m_.find(find(a[i]))==m_.end()){
                m_[a[i]]=true;
                re++;
            }
        }
        return re;
    }
    void combine(long long x,long long y){
        long long root_x=find(x);
        long long root_y=find(y);
        if(root_x==root_y){
            return;
        }else{
            a[root_y]=root_x;
        }
    }
};
class Edge{
    public:
    pair<long long,long long>points;
    long long val;
    Edge(long long p1,long long p2,long long v){
        points=make_pair(p1,p2);
        val=v;
    }
    Edge(){}
    bool operator <(const Edge&other){
        return this->val<other.val;
    }
};
class Deal{
    public:
    long long n,m,p;
    vector<Edge>edge_set;
    DisjointSet ds;
    Deal(){
        cin>>n>>m>>p;
        long long a,b,c;
        ds=DisjointSet(n);
        for(long long i=0;i<m;i++){
            cin>>a>>b>>c;
            edge_set.push_back(Edge(a,b,c));
        }
        for(int i=1;i<=n;i++){
            edge_set.push_back(Edge(0,i,p));
        }
    }
    pair<long long,long long> kruskal(long long edge_limit){
        long long count=0;
        long long re=p;
        sort(edge_set.begin(),edge_set.end());
        for(long long i=0;i<edge_set.size()&&count<edge_limit;i++){
            if(ds.find(edge_set[i].points.first)!=ds.find(edge_set[i].points.second)){
                re+=edge_set[i].val;
                ds.combine(edge_set[i].points.first,edge_set[i].points.second);
                count++;
            }
        }
        return make_pair(re,count);
    }
    void solve(){
        pair<long long,long long>pai_r=kruskal(m);
        cout<<pai_r.first+(n-pai_r.second-1)*p;
    }
};
int main(){
    Deal().solve();
}