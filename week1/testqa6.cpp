  #include<iostream>
  #include<string>
  #include<stdio.h>
  using namespace std;
  int main(){
    string s;
    /*读取文件*/
    FILE*fp=freopen("in.txt","r",stdin);//将输入流重定向到文件in.txt
    cin>>s;
    cout<<s<<endl;
    // 将输入流重定向到键盘输入
    fflush(fp);
    freopen("/dev/tty","r",stdin);
    /*写入文件*/
    cin>>s;
    //将输出流重定向到out.txt文件
    freopen("out.txt","w",stdout);
    cout<<s;
  }