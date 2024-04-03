#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    int a[1000000];
    int element_num;
    int disjoint_sets_count;//记录互斥集合的数量
    DisjointSet(int n){
        element_num=n;
        disjoint_sets_count = n;//初始时每个元素都是一个不相交的集合
        for(int i=0;i<=n;i++){
            a[i]=i;
        }
    }
    DisjointSet(){}
    int find(int&index){
        if(a[index]==index){
            return index;
        }else{
            a[index]=find(a[index]);
            return a[index];
        }
    }
    int get_disjoinsets_count(){
        return disjoint_sets_count;//直接返回
    }
    bool combine(int&x,int&y){
        int root_x=find(x);
        int root_y=find(y);
        if(root_x==root_y){
            return false;
        }else{
            a[root_y]=root_x;
            disjoint_sets_count--;//合并后减少一个互斥集合
        }
        return true;
    }
};
class Deal{
    public:
    int n,m;
    DisjointSet ds;
    Deal(){
        cin>>n>>m;
        ds=DisjointSet(n);
    }
    void solve(){
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            ds.combine(a,b);
            cout<<ds.get_disjoinsets_count()-1<<endl;
        }
    }

};
int main(){
    Deal().solve();
}
