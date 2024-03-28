#include<bits/stdc++.h>
using namespace std;
class Deal{
    public:
    int n,k;
    vector<int>a;
    Deal(){
        cin>>n>>k;
        int g;
        for(int i=0;i<n;i++){
            cin>>g;
            a.push_back(g);
        }
    }
    void solve(){
        vector<int>max_ans;
        vector<int>min_ans;
        deque<int>max_dq,min_dq;
        //最小
        for(int i=0;i<n;i++){
            if(!min_dq.empty()&&min_dq.front()<=i-k){//
                min_dq.pop_front();
            }
            while(!min_dq.empty()&&a[i]<a[min_dq.back()]){//维护一个递增的队列
                min_dq.pop_back();
            }
            min_dq.push_back(i);
            if(i-k+1>=0){
                min_ans.push_back(a[min_dq.front()]);
            }
        }
        for(int i=0;i<min_ans.size();i++){
            cout<<min_ans[i]<<' ';
        }
                cout<<endl;
        //最大
        for(int i=0;i<n;i++){
            if(!max_dq.empty()&&max_dq.front()<=i-k){//如果队列最大的元素不在当前窗口内，则弹出,这里维护的是一个递减的队列
                max_dq.pop_front();
            }
            //如果待插入元素比队尾元素大，则为了维护队列的递减，弹出队尾元素
            while(!max_dq.empty()&&a[i]>a[max_dq.back()]){
                 max_dq.pop_back();
            }
            //队列为空/队列尾元素大于当前索引位置的元素，入队
            max_dq.push_back(i);
            //如果当前在窗口内，则队列的头元素就是最大值
            if(i-k+1>=0){
                max_ans.push_back(a[max_dq.front()]);
            }
        }
        for(int i=0;i<max_ans.size();i++){
            cout<<max_ans[i]<<' ';
        }
    }
};
int main(){
    Deal d=Deal();
    d.solve();
}