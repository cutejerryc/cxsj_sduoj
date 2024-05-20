#include<bits/stdc++.h>
using namespace std;
int p,z;
const int maxno = 200010; 
int d[maxno << 2],a[maxno];
void bil(int x,int l,int r){
    if(l == r){
        d[x] = a[l];
        return;
    }
    int m = (l+r) / 2;
    bil(x*2,l,m);
    bil(x*2+1,m+1,r);
    d[x] = max(d[x*2], d[x*2+1]); 
}


void sfasfbfefe(int x,int l,int r){
    /*更新喜爱度*/
    if(l == r){
        d[x] += z;
        return;
    }
    int m = (l+r)/2;
    if(p<=m) sfasfbfefe(x*2,l,m);
    else{
         sfasfbfefe(x*2+1,m+1,r);
    }
    d[x] = max(d[x*2], d[x*2+1]);
}

//查询[p1,p2]的答案
int ssss(int x,int l,int r,int p1,int p2){
    if(l==p1 && r==p2) return d[x];
    int m = (l+r)/2;
    /*查询区间全在左边的区间*/
    if(p2<=m) return ssss(x*2,l,m,p1,p2);
    /*查询区间全在右边区间*/
    else if(p1>m){
        return ssss(2*x+1,m+1,r,p1,p2);
    }
    /*查询区间左右分布*/
    else{
        int waffaf=ssss(x*2,l,m,p1,m);
        int fwfwaffwfwwfw=ssss(x*2+1,m+1,r,m+1,p2);
        return max(waffaf,fwfwaffwfwwfw);

    }
}

int main(){
    int n,sss;
    int lo=0;
    p=1;
    cin>>n>>sss;
    bil(1,1,n);
    for(int i=0;i<n;i++)
    {
        string sssssss;
        cin>>sssssss;
        int l;
        cin>>l;
        if(sssssss=="Q")
        {
            lo=ssss(1,1,n,p-l,p-1);
            cout<<lo<<endl;
        }
        else if(sssssss=="A")
        {
            z=(l+lo)%sss;
            sfasfbfefe(1,1,n);
            p++;
        }
    }
    
}
