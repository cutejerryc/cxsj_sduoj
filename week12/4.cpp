#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n;
    vector<int>a;
    vector<int>sub_length;
    Deal(){
        sub_length=vector<int>(1e6+1,INT32_MAX);
        cin>>n;
        int g;
        for(int i=0;i<n;i++){
            cin>>g;
            a.push_back(g);
        }
    }
    void solve(){
        int max_len=1;
        sub_length[max_len]=-INT32_MAX;
        for(int i=0;i<n;i++){
            if(sub_length[max_len]<a[i]){//如果对应的当前的元素比最长的子序列的莫为元素要大，就更新一下
                max_len+=1;
                sub_length[max_len]=a[i];
            }else{//如果比他小或者等于他，就找到第一个比他大的，替换不影响max_len还可以更新对应的对应长度的末尾元素
                int len = lower_bound(sub_length.begin(), sub_length.begin() + max_len,a[i])-sub_length.begin();
                sub_length[len]=a[i];
            }
        }
        cout<<max_len-1<<endl;
    }
};
int main(){
    Deal().solve();
}