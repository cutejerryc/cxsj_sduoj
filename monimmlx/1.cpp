#include<bits/stdc++.h>
#include<cmath>
using namespace std;
class Vector{
public:
    double x,y,z;
    Vector(){};
    Vector(const double&x_,const double&y_,const double&z_){
        this->x=x_,this->y=y_,this->z=z_;
    }
    double get_val(){
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }
    double operator *(const Vector&other){
        return this->x*other.x+this->y*other.y+this->z*other.z;
    }
    double get_cos(Vector&other) {
        return ((*this) * other) / ((other.get_val()));
    }
    Vector get_vector(const Vector&end){
        return Vector(end.x-this->x,end.y-this->y,end.z-this->z);
    }
    Vector c_vector(const double&c){
        return Vector(this->x*c,this->y*c,this->z*c);
    }
    Vector mul(Vector&other){
        return Vector(this->y*other.z-this->z*other.y,this->z*other.x-this->x*other.z,this->x*other.y-this->y*other.x);
    }
};
class Planet{
public:
    int id;
    Vector pos;
    vector<int>can_go;
    Vector force_wave;
    double force_press;
    Planet(){};
    Planet(const int&id_,const double&x_,const double&y_,const double&z_){
        id=id_;
        pos.x=x_,pos.y=y_,pos.z=z_;
    }
    void be_convert_force(Planet&source){
        Vector pq=source.pos.get_vector(pos);
        double cos=source.force_wave.get_cos(pq);
        force_wave=pq.c_vector(cos/pq.get_val());
    }
    void be_convert_force(Vector&force){
        force_wave=force;
    }
    void compute_press(vector<bool>&if_older,vector<Planet>&planet_set){//在传递引力波之后调用
        vector<int>can_convert;
        for(int i=0;i<can_go.size();i++){
            if(!if_older[can_go[i]]){
                can_convert.push_back(can_go[i]);
            }
        }
        if(can_convert.size()==0){
            force_press=force_wave.get_val();
            return;
        }else{
            double re=0;
            for(int i=0;i<can_convert.size();i++){
                if_older[can_convert[i]]=true;
                re+=(force_wave.mul(planet_set[can_convert[i]].force_wave)).get_val();
            }
            force_press=re;
        }
    }
    vector<int> convert_force(vector<Planet>&planet_set,vector<bool>&if_older){
        vector<int>can_convert;
        for(int i=0;i<can_go.size();i++){
            if(!if_older[can_go[i]]){
                can_convert.push_back(can_go[i]);
            }
        }
        for(int i=0;i<can_convert.size();i++){
            planet_set[can_convert[i]].be_convert_force(*this);
        }
        return can_convert;
    }
};
class Deal{
public:
    int n;
    vector<Planet>planet_set;
    vector<bool>if_older;
    int target_id;
    Vector ori_f;
    Deal(){
        cin>>n;
        if_older=vector<bool>(n+1,false);
        int x,y,z;
        planet_set.push_back(Planet(0,0,0,0));
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            planet_set.push_back(Planet(i,x,y,z));
        }
        int a,b;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            planet_set[a].can_go.push_back(b);
            planet_set[b].can_go.push_back(a);
        }
        cin>>target_id>>x>>y>>z;
        ori_f=Vector(x,y,z);
    }
    void solve(){
        queue<int>q;
        q.push(target_id);
        planet_set[target_id].be_convert_force(ori_f);
        if_older[target_id]=true;
        while(!q.empty()){
            vector<int>tmp=vector<int>(0);
            int front=q.front();
            q.pop();
            tmp=planet_set[front].convert_force(planet_set,if_older);
            planet_set[front].compute_press(if_older,planet_set);
            for(int i=0;i<tmp.size();i++){
                q.push(tmp[i]);
            }
        }
        for(int i=1;i<planet_set.size();i++){
            cout<<fixed<<setprecision(9)<<planet_set[i].force_press<<endl;
        }
    }
};
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        Deal().solve();
    }
}