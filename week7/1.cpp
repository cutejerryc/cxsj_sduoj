#include<bits/stdc++.h>
using namespace std;
class Circle{
    public:
    long long int center,radius;
    double rec_start_pos,rec_end_pos;
    Circle(const long long int&c,const long long int&r,const long long int&w,const long long int&l):center(c),radius(r){//w是对应的矩形的高
        if(r<=w/2.0){
            rec_start_pos=-1;
            rec_end_pos=-1;
        }else{
            double tmp=sqrt(pow(r,2)-pow(double(w/2.0),2));
            rec_end_pos=center+tmp<=l?center+tmp:l;
            rec_start_pos=center-tmp>=0?center-tmp:0;
        }
    };
    bool operator <(const Circle&other){
        return this->rec_start_pos<other.rec_start_pos;
    }
    Circle(){};
};
class Deal{
    public:
    long long int n,l,w;
    vector<Circle>circle_set;
    long long int min_num=0;
    Deal(){
        cin>>n>>l>>w;
        long long int c,r;
        vector<Circle>circle_tmp;
        for(long long int i=0;i<n;i++){
            cin>>c>>r;
            Circle tmp=Circle(c,r,w,l);
            if(tmp.rec_start_pos!=-1){
                circle_tmp.push_back(tmp);
            }
        }
        sort(circle_tmp.begin(),circle_tmp.end());
        long long int start_now=circle_tmp[0].rec_start_pos;
        circle_set.push_back(circle_tmp[0]);
        for(long long int i=1;i<circle_tmp.size();i++){
            if(start_now==circle_tmp[i].rec_start_pos){
                continue;
            }else{
                circle_set.push_back(circle_tmp[i]);
                start_now=circle_tmp[i].rec_start_pos;
            }
        }
        circle_set=circle_tmp;
    }
    void solve(){
        long long int re=0;
        double start_pos=0,end_pos;
        double tmp_end_pos=0;
        long long int ind=0;
        while(tmp_end_pos<l){
            end_pos=tmp_end_pos;
            while(ind<circle_set.size()&&circle_set[ind].rec_start_pos<=end_pos){
                if(circle_set[ind].rec_end_pos>tmp_end_pos){
                    tmp_end_pos=circle_set[ind].rec_end_pos;
                }
                ind++;
            }
            if(end_pos==tmp_end_pos){
                cout<<-1<<endl;
                return;
            }
            re++;
        }
        cout<<re<<endl;
    };
};
int main(){
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        Deal().solve();
    }
}
