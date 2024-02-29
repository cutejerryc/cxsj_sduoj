#include <iostream>
#include <stdio.h>
#include<fstream>
using namespace std;
void fre_open(){
     string s;
    // 重定向输入流
    freopen("in.txt", "r", stdin);
    cin>>s;
    cout<<"in.txt cin->"<<s;
    // 重定向输出流
    freopen("out.txt", "w", stdout);
    cout<<"out.txt cout";
}
void io_fstream(){
  //重定向输入
  ifstream in("in.txt");
  streambuf *inbuf=cin.rdbuf();
  cin.rdbuf(in.rdbuf());//输入的缓冲区设置为in的
  string s;
  std::cin>>s;
  cout<<s;
  cin.rdbuf(inbuf);//恢复
  //重定向输出
  ofstream out("out.txt");
  streambuf *outbuf=cout.rdbuf();
  cout.rdbuf(out.rdbuf());
  cin>>s;
  cout<<s;
}
int main() {
  io_fstream();
  return 0;
}
