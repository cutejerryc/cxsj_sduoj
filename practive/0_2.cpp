#include<bits/stdc++.h>
using namespace std;
class Compare1{
public:
    bool operator()(const vector<long long int>&a,const vector<long long int>&b)const{
        return a[0]<b[0];
    }
};
class Compare2{
public:
    bool operator()(const vector<long long int>&a,const vector<long long int>&b)const{
        return a[1]<b[1];
    }
};
long long int n,c,d_l,d_w,l_pos=0,w_pos=0,l_num=0,w_num=0;
bool if_l_can_shoot=false,if_w_can_shoot=false;
unordered_map<long long int,set<vector<long long int>,Compare1>>l_map;
unordered_map<long long int,set<vector<long long int>,Compare2>>w_map;
unordered_map<long long int,long long int>x_y;
unordered_map<long long int,long long int>y_x;
void l_walk(){
    if_l_can_shoot=false;
    for(int i=0;i<=d_l;i++){
        if(l_map.find(l_pos)!=l_map.end()){//l移动到了有靶子的地方,注意，为了保持这里的正确性，需要在shoot的时候发现这一列为0时删除对应的set
            if_l_can_shoot=true;
            break;
        }
        l_pos=l_pos+1;
    }
}
void w_walk(){
    if_w_can_shoot=false;
    for(int i=0;i<=d_w;i++){
        if(w_map.find(w_pos)!=w_map.end()){
            if_w_can_shoot=true;
            break;
        }
        w_pos=w_pos+1;
    }
}
void l_shoot(long long int pos){
    if(if_l_can_shoot){
        int c_tmp=c;
        while(c_tmp!=0&&l_map[pos].size()!=0){
            int x_p=(*(l_map[pos].begin()))[0];
            l_map[pos].erase(l_map[pos].begin());
            w_map[x_p]
        }
    }
}
void w_shoot(long long int pos){
    if(if_w_can_shoot){

    }
}
int main(){
    cin>>n>>c>>d_l>>d_w;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        l_map[x].insert(vector<long long int>({x,y}));
        l_map[y].insert(vector<long long int>({x,y}));
        x_y[x]=y;
        y_x[y]=x;
    }
    int l_count=0,w_count=0;
    while(n>0){
        
    }
}