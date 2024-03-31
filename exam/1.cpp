#include<bits/stdc++.h>
using  namespace std;
unordered_map<string,bool>used_ip,used_name;
unordered_map<string,string>name_ip_map;
unordered_map<string,string>ip_name_map;
string int_to_4string(int a){
    string re="0000";
    int i=1;
    while(a!=0){
        re[4-i]=a%10+48;
        a/=10;
        i++;
    }
    return re;
}
int string_to_int(string s){
    int re;
    re=1000*(s[0]-48)+100*(s[1]-48)+10*(s[2]-48)+(s[3]-48);
    return re;
}
class Passage{
public:
    string origin_msg;
    string version;
    string source_ip,target_ip;
    string status_code;
    string status_version;
    string data_length_string;
    int data_length;
    string data;
    int type;//注册1 注销2 聊天3 其他0
    Passage(string ori){
        origin_msg=ori;
        int p=0;
        for(int i=0;i<origin_msg.size();i++){
            if(origin_msg[i]=='*'){
                p=i;
                version=string(origin_msg.begin()+3,origin_msg.begin()+p);
                break;
            }
        }
        p++;//进入ip字段
        source_ip=string(origin_msg.begin()+p,origin_msg.begin()+p+12);
        target_ip=string(origin_msg.begin()+p+12,origin_msg.begin()+p+24);
        status_code=string(origin_msg.begin()+p+24,origin_msg.begin()+p+25);
        status_version=string(origin_msg.begin()+p+25,origin_msg.begin()+p+27);
        data_length_string=string(origin_msg.begin()+p+27,origin_msg.begin()+p+31);
        data=string(origin_msg.begin()+p+31,origin_msg.end());
        if(status_code=="1"&&status_version=="00"){
            type=1;
        }else if(status_code=="1"&&status_version=="02"){
            type=2;
        }else if(status_code=="0"&&status_version=="08"){
            type=3;
        }else{
            type=0;
        }
    };
    bool if_refuse_request(){
        if(source_ip=="022222222222"||source_ip=="099999999999"){
            return true;
        }
        if(version!="23"){
            return true;
        }
        if(target_ip!="022222222222"){
            return true;
        }
        if(type==0){
            return true;
        }
        return false;
    }
    bool if_name_ok(){
        if(data.size()<1){
            return false;
        }
        for(int i=0;i<data.size();i++){
            if(data[i]>=97&data[i]<=122){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    bool if_name_repeat(){
        if(used_name.find(data)!=used_name.end()&&used_name[data]){
            return true;
        }
        return false;
    }
    bool if_ip_repeat(){
        if(used_ip.find(source_ip)!=used_ip.end()&&used_ip[source_ip]){
            return true;
        }
        return false;
    }
    bool if_name_ip_matched(){
        if(name_ip_map.find(data)!=name_ip_map.end()&&name_ip_map[data]==source_ip){
            return true;
        }
        return false;
    }
    void deal(){
        if(type==1){
            if(!if_refuse_request()&&!if_name_repeat()&&!if_ip_repeat()&&if_name_ok()&&target_ip=="022222222222"){
                used_ip[source_ip]=true;
                used_name[data]=true;
                name_ip_map[data]=source_ip;
                ip_name_map[source_ip]=data;
                cout<<"Ver23*"+target_ip+source_ip+"101"+ int_to_4string(data.length())+data;
            }
        }else if(type==2){
            if(!if_refuse_request()&&if_name_ip_matched()){
                used_ip[source_ip]= false;
                used_name[data]= false;
                name_ip_map[data]="@";
                cout<<"Ver23*"+target_ip+source_ip+"103"+ int_to_4string(data.length())+data;
            }
        }else if(type==3){
            if(!if_refuse_request()&&if_ip_repeat()){
                cout<<"Ver23*022222222222099999999999099"+ int_to_4string(data.length()+ip_name_map[source_ip].length()+1)+ip_name_map[source_ip]+":"+data;
            }
        }else{

        }
    }
};
class Deal1{
public:
    int n;
    vector<Passage>passages;
    Deal1(){
        cin>>n;
        getchar();
        int n_p=0;
        char c;
        string s="";
        while(n_p!=n){
            c=getchar();
            s+=c;
            if(c=='*') {
                for(int i=0;i<24+3;i++){
                    c=getchar();
                    s+=c;
                }
                string num_s="";
                for(int i=0;i<4;i++){
                    c=getchar();
                    s+=c;
                    num_s+=c;
                }
                int data_len= string_to_int(num_s);
                for(int i=0;i<data_len;i++){
                    c=getchar();
                    s+=c;
                }
                passages.push_back(Passage(s));
                s="";
                n_p++;
            }
        }
    }
    void server_deal(){
        for(int i=0;i<n;i++){
            passages[i].deal();
        }
    }
};
int main(){
    Deal1().server_deal();
}