#include<bits/stdc++.h>
using namespace std;
class VillageMap{
    public:
    int node_num;
    int dis_p=-1;
    vector<vector<int>>m_ap;
    VillageMap(int node_nu){
        node_num=node_nu;
        for(int i=0;i<=node_num;i++){
            m_ap.push_back(vector<int>(0));
        }
    }
    VillageMap(){}
    void add(pair<int,int>p){
        m_ap[p.first].push_back(p.second);
        m_ap[p.second].push_back(p.first);
    }
    int dfs(vector<int>&max_set,vector<bool>&if_visit,int dist,int node){
        int max_dis=0;
        if_visit[node]=true;
        for(int i=0;i<m_ap[node].size();i++){
            if(!if_visit[m_ap[node][i]]){
                int tmp_d=dfs(max_set,if_visit,dist+1,m_ap[node][i])+1;
                max_dis=max_dis>tmp_d+dist?max_dis:tmp_d+dist;
            }
        }
        max_set[node]=dist;
        return max_dis;
    }
};
class Deal{
    public:
    int n;
    VillageMap vm;
    vector<int>max_dis1;
    vector<int>max_dis2;
    vector<int>max_dis3;
    Deal(){
        cin>>n;
        vm=VillageMap(n);
        max_dis1=vector<int>(n+1,-1);
        max_dis2=vector<int>(n+1,-1);
        max_dis3=vector<int>(n+1,-1);
        int a,b;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            vm.add(make_pair(a,b));
        }
    }
    void solve(){
        int max_p;
        vector<bool>if_v1(n+1,false);
        vm.dfs(max_dis1,if_v1,0,1);
        int m_1=-1;
        for(int i=0;i<max_dis1.size();i++){
            if(max_dis1[i]>m_1){
                m_1=max_dis1[i];
                max_p=i;
            }
        }
        vector<bool>if_v2(n+1,false);
        vm.dfs(max_dis2,if_v2,0,max_p);
        m_1=-1;
        for(int i=0;i<max_dis2.size();i++){
            if(max_dis2[i]>m_1){
                m_1=max_dis2[i];
                max_p=i;
            }
        }
        vector<bool>if_v3(n+1,false);
         vm.dfs(max_dis3,if_v3,0,max_p);
        for(int i=1;i<=n;i++){
            cout<<(max_dis2[i]>max_dis3[i]?max_dis2[i]:max_dis3[i])<<' ';
        }
        cout<<endl;
    }
};
int main(){
    Deal().solve();
}