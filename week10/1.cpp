#include<bits/stdc++.h>
using namespace std;
class Object{//化合物
    public:
    string s;
    int times=1;
    Object(string s_):s(s_){
        for(int i=0;i<s.size();i++){//在所有没有系数的括号后添加1
            if(s[i]==')'&&(i+1==s.size()||(i+1!=s.size()&&s[i+1]<48&&s[i+1]>57))){
                s.insert(s.begin()+i+1,'1');
            }
        }
        stack<int>sk;
        for(int i=s.size()-1;i>=0;){
            pair<string,int>tmp=get_part(i);
            if(tmp.second>0){//元素
                if(index_map.find(tmp.first)==index_map.end()){//这个元素还没出现过
                    elements.push_back(tmp.first);
                    num_map[tmp.first]=0;
                    index_map[tmp.first]=elements.size()-1;
                }else{

                }
                num_map[tmp.first]+=tmp.second*times;
            }else if(tmp.second==0){//括号数字
                int t=string_to_int(tmp.first);
                times*=t;
                sk.push(t);
            }else{//括号
                if(tmp.first=="("){
                    if(!sk.empty()){//这个判断用于排除类似(Cu2O)3CO3的情况
                        times/=sk.top();
                        sk.pop();
                    }
                }
            }
        }
    }
    int string_to_int(string&s){
        int re=0;
        for(int i=0;i<s.size();i++){
            re=re*10+s[i]-48;
        }
        return re;
    }
    vector<string>elements;
    unordered_map<string,int>num_map;
    unordered_map<string,int>index_map;
    pair<string,int>get_part(int&ind){//正数->元素 -1->括号，0数字
        string tmp="";
        char c=s[ind];
        ind--;
        tmp+=c;
        if(c=='('||c==')'){
            return make_pair(tmp,-1);
        }else if(c>=48&&c<=57){
            while(s[ind]>=48&&s[ind]<=57){
                tmp.insert(tmp.begin(),s[ind]);
                ind--;
            }
            if(s[ind]!=')'){//如果这个数字前面不是括号，那就是元素，直接返回元素
                pair<string,int>t=get_part(ind);
                int times=string_to_int(tmp);
                t.second*=times;
                return t;
            }
            return make_pair(tmp,0);
        }else if(c>=97&&c<=122){
            while(s[ind]<65||s[ind]>90){
                tmp.insert(tmp.begin(),s[ind]);
                ind--;
            }
            tmp.insert(tmp.begin(),s[ind]);
            ind--;
            return make_pair(tmp,1);
        }else{
            return make_pair(tmp,1);
        }
    }
};
class Part{//化学方程式任意一侧
    public:
    vector<Object>objects;
    vector<string>elements;
    unordered_map<string,int>element_nums;\
    Part(){}
    Part(string s){
        vector<string>ob_set;
        vector<int>ob_para;
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='+'){
                ob_set.push_back(tmp);
                tmp="";
                continue;
            }
            tmp+=s[i];
        }
        ob_set.push_back(tmp);
        for(int i=0;i<ob_set.size();i++){//处理前面的系数
            int times=0;
            for(int u=0;u<ob_set[i].size();u++){
                if(ob_set[i][u]>=48&&ob_set[i][u]<=57){
                    times=times*10+ob_set[i][u]-48;
                }else{
                    objects.push_back(Object(ob_set[i].substr(u)));
                    break;
                }
            }
            if(times==0){
                times=1;
            }
            ob_para.push_back(times);
        }
        //根据系数更新对应的元素
        for(int i=0;i<objects.size();i++){
            for(int u=0;u<objects[i].elements.size();u++){
                objects[i].num_map[objects[i].elements[u]]*=ob_para[i];
            }
        }
        //更新nums
        for(int i=0;i<objects.size();i++){
            for(int u=0;u<objects[i].elements.size();u++){
                if(element_nums.find(objects[i].elements[u])==element_nums.end()){
                    elements.push_back(objects[i].elements[u]);
                    element_nums[objects[i].elements[u]]=0;
                }
                element_nums[objects[i].elements[u]]+=objects[i].num_map[objects[i].elements[u]];
            }
        }
    }
};
class Deal{//化学方程式的判断
    public:
    Part left,right;
    string s;
    Deal(){
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='='){
                left=Part(s.substr(0,i));
                right=Part(s.substr(i+1));
            }
        }
    }
    bool solve(){
        if(left.elements.size()!=right.elements.size()){
            return false;
        }
        for(int i=0;i<left.elements.size();i++){
            if(right.element_nums.find(left.elements[i])==right.element_nums.end()){
                return false;
            }else if(right.element_nums[left.elements[i]]!=left.element_nums[left.elements[i]]){
                return false;
            }
        }
        return true;
    }
};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        if(Deal().solve()){
            cout<<'Y'<<endl;
        }else{
            cout<<'N'<<endl;
        }
    }
}