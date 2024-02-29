### 解法
  - 在输入时确定对应的最左端的人位置l和最右端的人位置r
  - 对l与r之间的所有位置遍历计算代价，并与之前的最小代价比较，取较小者作为新的最小代价
### 时间复杂度
$$
O((r-l)\bullet n)
$$
> 解释： 对于每一个遍历的点计算最小代价的操作次数为n，而遍历的次数为r-l
```cpp
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int get_val(int&u,vector<int>&a){//计算一个点的代价
    int re=0;
    for(int i=0;i<a.size();i++){
        re+=pow((a[i]-u),2);
    }
    return re;
}
int main(){
    int n;
    int l=INT32_MAX,r=INT32_MIN;
    int min_val=INT32_MAX;
    vector<int>a;
    cin>>n;
    int g;
    for(int i=0;i<n;i++){
        cin>>g;
        if(g<l){//更新l
            l=g;
        }
        if(g>r){//更新r
            r=g;
        }
        a.push_back(g);
    }
    for(int i=l;i<=r;i++){//在l与r之间寻找最小代价点
        int tmp=get_val(i,a);
        if(tmp<min_val){
            min_val=tmp;
        }
    }
    cout<<min_val;
    return 0;
}
```