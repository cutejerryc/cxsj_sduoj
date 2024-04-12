#include<bits/stdc++.h>
using namespace std;
class Cube{
    public:
    string last_op_set="";
    vector<vector<int>>cube={{0,0,0,0},{0,0,0,0}};
    long long int sign=0;
    Cube(bool coo){
        for(int i=0;i<4;i++){
            cin>>cube[0][i];
        }
        for(int i=3;i>=0;i--){
            cin>>cube[1][i];
        }
        compute_sign();
    }
    Cube(){
        sign=0;
        cube={{1,2,3,4},{8,7,6,5}};
        for(int i=0;i<8;i++){
            sign=sign*10+cube[i/4][i%4];
        }
    }
    void compute_sign(){
        sign=0;
        for(int i=0;i<8;i++){
            sign=sign*10+cube[i/4][i%4];
        }
    }
    Cube op_A()const{
        Cube cube1;
        cube1.cube=cube;
        int g;
        for(int i=0;i<4;i++){
            g=cube1.cube[1][i];
            cube1.cube[1][i]=cube1.cube[0][i];
            cube1.cube[0][i]=g;
        }
        cube1.compute_sign();
        cube1.last_op_set=this->last_op_set;
        return cube1;
    }
    Cube op_B()const{
        Cube cube1;
        cube1.cube=cube;
        int a=cube[0][3],b=cube[1][3];
        int l_a,l_b;
        for(int i=0;i<4;i++){
            cube1.cube[0][i]=a;
            cube1.cube[1][i]=b;
            a=cube[0][i];
            b=cube[1][i];
        }
        cube1.compute_sign();
        cube1.last_op_set=this->last_op_set;
        return cube1;
    }
    Cube op_C()const{
        Cube cube1;
        cube1.cube=cube;
        int a=cube[0][1],b=cube[0][2],c=cube[1][1],d=cube[1][2];
        cube1.cube[0][1]=c;
        cube1.cube[0][2]=a;
        cube1.cube[1][1]=d;
        cube1.cube[1][2]=b;
        cube1.compute_sign();
        cube1.last_op_set=this->last_op_set;
        return cube1;
    }
    bool operator==(const Cube&other){
        return this->sign==other.sign;
    }
    bool operator <(const Cube&other){
        return last_op_set<other.last_op_set;
    }
    void out(){
        cout<<endl;
        for(int i=0;i<2;i++){
            for(int u=0;u<4;u++){
                cout<<cube[i][u]<<' ';
            }
            cout<<endl;
        }
    }
};
struct CompareCube{
       bool operator()(const Cube&thi,const Cube&other){
        return thi.last_op_set>other.last_op_set;
    } 
};
class Deal{
    public:
    Cube target_cube;
    Deal(){
        target_cube=Cube(0);
    }
    void bfs(){
        priority_queue<Cube,vector<Cube>,CompareCube>pq;
        int size=1;
        pq.push(Cube());
        if(Cube()==target_cube){
            cout<<0<<endl<<endl;
        }
        unordered_map<long long int,bool>_m;
        _m[pq.top().sign]=true;
        while(!pq.empty()){
            size=pq.size();
            vector<Cube>ttt;
            for(int i=0;i<size;i++){
                ttt.push_back(pq.top());
                pq.pop();
            }
            for(int i=0;i<ttt.size();i++){
                Cube tmp=ttt[i].op_A();
                tmp.compute_sign();
                if(_m.find(tmp.sign)==_m.end()){
                    _m[tmp.sign]=true;
                    tmp.last_op_set=tmp.last_op_set+"A";
                    if(tmp==target_cube){
                        cout<<tmp.last_op_set.size()<<endl;
                        cout<<tmp.last_op_set<<endl;
                        return;
                    }
                    pq.push(tmp);
                }
                tmp=ttt[i].op_B();
                tmp.compute_sign();
                if(_m.find(tmp.sign)==_m.end()){
                    _m[tmp.sign]=true;
                    tmp.last_op_set=tmp.last_op_set+"B";
                    if(tmp==target_cube){
                        cout<<tmp.last_op_set.size()<<endl;
                        cout<<tmp.last_op_set<<endl;
                        return;
                    }
                    pq.push(tmp);
                }
                tmp=ttt[i].op_C();
                tmp.compute_sign();
                if(_m.find(tmp.sign)==_m.end()){
                    _m[tmp.sign]=true;
                    tmp.last_op_set=tmp.last_op_set+"C";
                    if(tmp==target_cube){
                        cout<<tmp.last_op_set.size()<<endl;
                        cout<<tmp.last_op_set<<endl;
                        return;
                    }
                    pq.push(tmp);
                }
            }
        }
    }
    void solve(){
        bfs();
    }
};
int main(){
    Deal d=Deal();d.solve();
}