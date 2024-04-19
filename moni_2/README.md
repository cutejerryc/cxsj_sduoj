## 解法
### `Chat` 类

- 构造函数：
  - 初始化 `like` 为指定值或默认值 `-1`，`num` 为 `0`

### `ChatList` 类

- 成员变量：
  - `chat_list`：存储 `Chat` 对象的列表
  - `top`：表示当前位于顶部的聊天窗口索引，初始值为 `-1`，表示队列为空

- 方法：
  - `find_chat_by_like(u)`：查找具有给定 喜爱度 `u` 的聊天窗口的索引，返回索引或 `-1`表示为找到
  - `find_max_like_chat()`：查找具有最大 喜爱度的聊天窗口索引，返回索引
  - `update_top(x)`：将 `top` 更新为正确的值，当移动第 `x` 个聊天窗口到队首时调用
  - `move_to_first(x)`：将第 `x` 个聊天窗口移动到队首，并更新 `top`
  - `add(u)`：添加一个具有 喜爱度 `u` 的新聊天窗口，若已存在同喜好程度的窗口，则提示“same likeness”
  - `close(u)`：关闭具有 喜爱度 `u` 的聊天窗口，更新 `num` 并从列表中移除该窗口。同时更新 `top`
  - `chat(w)`：给当前顶部聊天窗口增加聊天次数 `w`。如果队列为空，则提示“empty”
  - `rotate(x)`：将列表中第 `x` 个聊天窗口移动到队首，检查输入是否有效范围
  - `prior()`：将具有最大喜爱度的聊天窗口移动到队首
  - `choose(u)`：将具有 喜爱度 `u` 的聊天窗口移动到队首
  - `_top(u)`：直接将具有 喜爱度 `u` 的聊天窗口设置为顶部窗口
  - `untop()`：清除当前顶部聊天窗口（将其设为非顶部状态）
### `Deal` 类
- 构造函数：读取整数 `t`，表示测试用例数量。
- `solve()`：处理所有测试用例。
  1. 对于每个测试用例：
     1. 读取整数 `n`，表示操作数量
     2. 创建 `ChatList` 对象 `cl`
     3. 循环执行 `n` 次操作：
        1. 读取操作名 `s` 和传入的参数
        2. 根据操作名调用 `cl` 的相应方法。
        3. 更新全局操作计数器 `kk`。
     4. 输出顶部聊天窗口（如果存在且有聊天次数）的告别消息（“Bye like: num.”）
     5. 清空顶部聊天窗口的聊天次数
     6. 输出所有非顶部但仍有聊天次数的聊天窗口的告别消息

### 主函数 `main()`
创建一个 `Deal` 对象并调用其 `solve()` 方法来处理所有测试用例。
## 时间复杂度
$$
O(t\cdot n^2)
$$
- 一共进行t次测试，每次测试输入n个操作，每次操作的时间复杂度最大为n，则对应的时间复杂度为t*n*n 
## 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
long long int kk=0;
class Chat{
    public:
    long long int like;
    long long int num;
    Chat(){num=0;like=-1;};
    Chat(long long int u){num=0,like=u;}
};
class ChatList{
    public:
    vector<Chat>chat_list;
    long long int top=-1;
    long long int find_chat_by_like(long long int u){
        for(long long int i=0;i<chat_list.size();i++){
            if(chat_list[i].like==u){
                return i;
            }
        }
        return -1;
    }
    long long int find_max_like_chat(){
        long long int max=-INT64_MAX,max_id=-1;
        for(long long int i=0;i<chat_list.size();i++){
            if(chat_list[i].like>max){
                max=chat_list[i].like;
                max_id=i;
            }
        }
        return max_id;
    }
    void update_top(long long int x){//在将第x个窗口移到队首时更新top
        if(top==x-1&&top!=-1){
            top=0;
        }else if(top<x-1&&top!=-1){
            top++;
        }
    }
    void move_to_first(long long int x){
        Chat tmp=chat_list[x-1];
        update_top(x);
        chat_list.erase(chat_list.begin()+x-1,chat_list.begin()+x);
        chat_list.insert(chat_list.begin(),tmp);
    }
    void add(long long int u){
        if(find_chat_by_like(u)!=-1){
            cout<<"OpId #"+to_string(kk+1)<<":"<<" same likeness."<<endl;return;
        }
        chat_list.push_back(Chat(u));
        cout<<"OpId #"+to_string(kk+1)<<":"<<" success."<<endl;return;
    }
    void close(long long int u){
        long long int id=find_chat_by_like(u);
        if(id==-1){
            cout<<"OpId #"+to_string(kk+1)<<":"<<" invalid likeness."<<endl;return;
        }
        if(id==top){
            top=-1;
        }else if(id<top){
            top--;
        }
        cout<<"OpId #"+to_string(kk+1)<<":"<<" close "+to_string(u)+" with "+to_string(chat_list[id].num)+"."<<endl;
        chat_list.erase(chat_list.begin()+id,chat_list.begin()+id+1);
        return;
    }
    void chat(long long int w){
        if(chat_list.size()<=0){
            cout<<"OpId #"+to_string(kk+1)<<":"<<" empty."<<endl;return;
        }
        if(top>=0){
            chat_list[top].num+=w;
        }else{
            chat_list[0].num+=w;
        }
        cout<<"OpId #"+to_string(kk+1)<<":"<<" success."<<endl;return;
    }
    void rotate(long long int x){
        if(x>chat_list.size()||x<1){
            cout<<"OpId #"+to_string(kk+1)<<":"<<" out of range."<<endl;return;
        }
        move_to_first(x);
        cout<<"OpId #"+to_string(kk+1)<<":"<<" success."<<endl;return;
    }
    void prior(){
        if(chat_list.size()==0){
            cout<<"OpId #"+to_string(kk+1)<<":"<<" empty."<<endl;return;
        }
        long long int id=find_max_like_chat()+1;
        move_to_first(id);
        cout<<"OpId #"+to_string(kk+1)<<":"<<" success."<<endl;return;
    }
    void choose(long long int u){
        long long int id=find_chat_by_like(u);
        if(id==-1){
            cout<<"OpId #"+to_string(kk+1)<<":"<<" invalid likeness."<<endl;return;
        }
        id=id+1;
        move_to_first(id);
        cout<<"OpId #"+to_string(kk+1)<<":"<<" success."<<endl;return;
    }
    void _top(long long int u){
        long long int id=find_chat_by_like(u);
        if(id==-1){
            cout<<"OpId #"+to_string(kk+1)<<":"<<" invalid likeness."<<endl;return;
        }
        top=id;
        cout<<"OpId #"+to_string(kk+1)<<":"<<" success."<<endl;return;
    }
    void untop(){
        if(top==-1){
            cout<<"OpId #"+to_string(kk+1)<<":"<<" no such person."<<endl;return;
        }else{
            top=-1;
            cout<<"OpId #"+to_string(kk+1)<<":"<<" success."<<endl;return;
        }
    }
};
class Deal{
    public:
    long long int t;
    long long int n;
    Deal(){
        cin>>t;;
    }
    void solve(){
        for(long long int i=0;i<t;i++){
            kk=0;
            cin>>n;
            ChatList cl;
            long long int g;
            string s;
            for(long long int u=0;u<n;u++){
                cin>>s;
                if(s=="Add"){
                    cin>>g;
                    cl.add(g);
                }else if(s=="Close"){
                    cin>>g;
                    cl.close(g);
                }else if(s=="Chat"){
                    cin>>g;
                    cl.chat(g);
                }else if(s=="Rotate"){
                    cin>>g;
                   cl.rotate(g);
                }else if(s=="Prior"){
                    cl.prior();
                }else if(s=="Choose"){
                    cin>>g;
                    cl.choose(g);
                }else if(s=="Top"){
                    cin>>g;
                    cl._top(g);
                }else if(s=="Untop"){
                    cl.untop();
                }
                kk++;
            }
            if(cl.top!=-1){
                if(cl.chat_list[cl.top].num!=0){
                    cout<<"OpId #"+to_string(kk+1)<<": "<<"Bye "+to_string(cl.chat_list[cl.top].like)+": "+to_string(cl.chat_list[cl.top].num)+"."<<endl;
                    kk++;
                }
                cl.chat_list[cl.top].num=0;
            }
            for(long long int u=0;u<cl.chat_list.size();u++){
                if(cl.chat_list[u].num!=0){                
                    cout<<"OpId #"+to_string(kk+1)<<": "<<"Bye "+to_string(cl.chat_list[u].like)+": "+to_string(cl.chat_list[u].num)+"."<<endl;
                    kk++;
                }
            }
        }
    }
};
int main(){
    Deal().solve();
}
```