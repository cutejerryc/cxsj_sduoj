#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int g2(int a){
    string tmp=std::to_string(a);//整数转换为字符串
    std::sort(tmp.begin(),tmp.end());//字符串进行排序(按照acsii码)
    return std::stoi(tmp);//字符串转换为整数
}
int g1(int a){
    string tmp=std::to_string(a);
    std::sort(tmp.begin(),tmp.end());
    std::reverse(tmp.begin(),tmp.end());//排序后逆置字符串
    return std::stoi(tmp);
}
int f(int a){
    return g1(a)-g2(a);
}
int main(){
    int a;
    int k;
    cin>>a>>k;
    for(int i=0;i<k;i++){//迭代推导至第k项
        a=f(a);
    }
    cout<<a;
}
