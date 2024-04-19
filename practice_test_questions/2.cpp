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