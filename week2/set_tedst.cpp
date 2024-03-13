#include<bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(const int&a,const int&b)const{
        return a>b;
    }
};
int main(){
    set<int,Compare>a;
    for(int i=0;i<10;i++){
        a.insert(i);
    }
    set<int>::iterator it=a.begin();
    while(it!=a.end()){
        cout<<*it<<' ';
        it++;
    }
}