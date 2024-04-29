#include<bits/stdc++.h>
using namespace std;
class Vertex{
    public:
    int id;
    vector<int>target_vertex_set;
    int in_degree;
    Vertex(const int&i_):id(i_),in_degree(0){}
};
class TopSort{
    public:
    int n;
    vector<Vertex>vertex_set;
    vector<int>re;
    priority_queue<int,vector<int>,greater<int>>pq;
    TopSort(int n){
        for(int i=0;i<n;i++){
            vertex_set.push_back(Vertex(i+1));
        }
        int m;
        cin>>m;
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            vertex_set[a-1].target_vertex_set.push_back(b);
            vertex_set[b-1].in_degree++;
        }
        for(int i=0;i<n;i++){
            if(vertex_set[i].in_degree==0){
                pq.push(i+1);
            }
        }
    }
    TopSort(){}
    void sort(){
        while(!pq.empty()){
            int tmp=pq.top();
            re.push_back(tmp);
            pq.pop();
            for(int i=0;i<vertex_set[tmp-1].target_vertex_set.size();i++){
                vertex_set[vertex_set[tmp-1].target_vertex_set[i]-1].in_degree--;
                if(vertex_set[vertex_set[tmp-1].target_vertex_set[i]-1].in_degree==0){
                    pq.push(vertex_set[tmp-1].target_vertex_set[i]);
                }
            }
        }
    }
};
class Deal{
    public:
    int n;
    TopSort tp;
    Deal(){
        cin>>n;
        tp=TopSort(n);
    }
    void solve(){
        tp.sort();
        for(int i=0;i<tp.re.size();i++){
            cout<<tp.re[i]<<' ';
        }
        cout<<endl;
    }
};
int main(){
    Deal().solve();
}