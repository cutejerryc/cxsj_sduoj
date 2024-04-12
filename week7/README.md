# 山东大学程序设计思维与实践作业-Week5
**仅作参考，切莫照搬，有查重**
# 代码题目
  - 1
  ```shell
  git clone https://github.com/W1412X/cxsj_sduoj.git
  ```
  - 2  
前往[点击此处](https://github.com/W1412X/cxsj_sduoj.git)获取

## A
### 题目
#### 题目描述

假设有一条长度为 l 米，宽度为 w 米的带状区域，共安装有 n 个喷水器。每个喷水器都位于该区域的水平中心线上，且已知每个喷水器距离中心线左端的距离和其覆盖范围半径。请计算最少需要开启多少个喷水器才能覆盖整个区域。若无法覆盖整个区域，则输出“-1”。

![2e04e35bbee711.png](https://oj.qd.sdu.edu.cn/api/filesys/download/431462708508963129/2e04e35bbee711.png)

#### 输入

多组数据。第一行一个整数 T 表示数据组数；

每组数据的第一行包含三个整数 n，l 和 w，其中 n≤15000。接下来的 n 行每行包含两个整数 pi​ 和 ri​，表示第 i 个喷水器距离中心线左端的距离和其覆盖范围半径。
#### 输出
对于每组数据，请输出最少需要的喷水器数量以覆盖整个区域。如果无法覆盖整个区域，请输出“-1”。
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class Circle{
    public:
    long long int center,radius;
    double rec_start_pos,rec_end_pos;
    Circle(const long long int&c,const long long int&r,const long long int&w,const long long int&l):center(c),radius(r){//w是对应的矩形的高
        if(r<=w/2.0){
            rec_start_pos=-1;
            rec_end_pos=-1;
        }else{
            double tmp=sqrt(pow(r,2)-pow(double(w/2.0),2));
            rec_end_pos=center+tmp<=l?center+tmp:l;
            rec_start_pos=center-tmp>=0?center-tmp:0;
        }
    };
    bool operator <(const Circle&other){
        return this->rec_start_pos<other.rec_start_pos;
    }
    Circle(){};
};
class Deal{
    public:
    long long int n,l,w;
    vector<Circle>circle_set;
    long long int min_num=0;
    Deal(){
        cin>>n>>l>>w;
        long long int c,r;
        vector<Circle>circle_tmp;
        for(long long int i=0;i<n;i++){
            cin>>c>>r;
            Circle tmp=Circle(c,r,w,l);
            if(tmp.rec_start_pos!=-1){
                circle_tmp.push_back(tmp);
            }
        }
        sort(circle_tmp.begin(),circle_tmp.end());
        long long int start_now=circle_tmp[0].rec_start_pos;
        circle_set.push_back(circle_tmp[0]);
        for(long long int i=1;i<circle_tmp.size();i++){
            if(start_now==circle_tmp[i].rec_start_pos){
                continue;
            }else{
                circle_set.push_back(circle_tmp[i]);
                start_now=circle_tmp[i].rec_start_pos;
            }
        }
        circle_set=circle_tmp;
    }
    void solve(){
        long long int re=0;
        double start_pos=0,end_pos;
        double tmp_end_pos=0;
        long long int ind=0;
        while(tmp_end_pos<l){
            end_pos=tmp_end_pos;
            while(ind<circle_set.size()&&circle_set[ind].rec_start_pos<=end_pos){
                if(circle_set[ind].rec_end_pos>tmp_end_pos){
                    tmp_end_pos=circle_set[ind].rec_end_pos;
                }
                ind++;
            }
            if(end_pos==tmp_end_pos){
                cout<<-1<<endl;
                return;
            }
            re++;
        }
        cout<<re<<endl;
    };
};
int main(){
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        Deal().solve();
    }
}
```
## B
### 题目
#### 题目描述

小明最近在学习数列，他想尝试一种新的操作方式。他在黑板上写下了一个长度为 n 的正整数数列，每次从中选择两个数 a 和 b，然后将它们从数列中删除，并添加一个新的数 a×b+1。这样的操作一直进行下去，直到最终只剩下一个数 x 为止。其中，数列中所有元素都是正整数。

现在，所有可能在最后得到的一个数 xi​ 构成了一个新数列 X，请你帮助小明计算出数列 X 的极差 M，即 X 中的最大值与最小值之差。

#### 输入

第一行为一个正整数 n，表示数列的长度。

接下来 n 行，每行输入一个正整数表示数列中的元素。

最后一行为一个 0，表示数据结束。

#### 输出

输出一个整数，即该数列的极差 M。

#### 数据范围与提示

对于全部数据，0≤n≤50000，保证所有数据计算均在 32 位有符号整数范围内。
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class Deal{
	public:
		int max_val=INT_MIN,min_val=INT_MAX;
		int n;
		vector<int>a;
		vector<int>final_a;
		int compute(const int&a,const int&b){
			return a*b+1;
		}
        void insert(vector<int>&a,int g,bool mode){
            bool if_insert=false;
            int i=0;
            if(mode){
                for(i=0;i<a.size();i++){
                    if(a[i]<g){
                        continue;
                    }else{
                        if_insert=true;
                        a.insert(a.begin()+i,g);
                        break;
                    }
                }
            }else{
                for(i=0;i<a.size();i++){
                    if(a[i]>g){
                        continue;
                    }else{
                        if_insert=true;
                        a.insert(a.begin()+i,g);
                        break;
                    }
                }
            }
            if(!if_insert){
                a.insert(a.begin()+i,g);
            }

        }
		Deal(){
			cin>>n;
			int g;
			for(int i=0;i<n;i++){
 				cin>>g;
				a.push_back(g);
			}
			cin>>g;
		}
		void solve(){
			sort(a.begin(),a.end());
            vector<int>b=a;
            reverse(b.begin(),b.end());
            int max_t,min_t;
            int size=a.size();
            for(int i=size-1;i>=0;i--){
                if(a.size()==2){
                    max_val=b[0]*b[1]+1;
                    min_val=a[0]*a[1]+1;
                    break;
                }
                max_t=b[i]*b[i-1]+1;
                min_t=a[i]*a[i-1]+1;
                a.pop_back();
                a.pop_back();
                b.pop_back();
                b.pop_back();
                insert(b,max_t,0);
                insert(a,min_t,1);
            }
            cout<<max_val-min_val<<endl;
		}
};
int main(){
	Deal().solve();
}
```
# C
### 题目
#### 题目描述

张三在山上建造了一座有 n 个小木屋的村庄，这些小木屋排成一条直线，第 i 个小木屋的位置为 xi​。但是，张三的 m 头山羊经常互相攻击，为了避免它们之间发生冲突，张三需要让这些山羊分散开来，每头山羊都要被安置在一个小木屋里。为了最大化山羊之间的距离，张三希望让任意两头山羊之间的最小距离尽可能大。

注意：为了防止山羊之间的冲突，张三需要保证每个小木屋最多只能有一只山羊。

#### 输入

第一行包含两个整数 n 和 m，表示小木屋的数量和山羊的数量。

接下来 n 行，每行一个整数， x1​,x2​,…,xn​，表示每个小木屋的位置。

#### 输出

输出一个整数，表示任意两头山羊之间的最小距离的最大值。

#### 数据范围与提示

2≤n≤105，0≤xi​≤109，2≤m≤n。
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class Deal{
	public:
	long long int n,m;
	vector<long long int>pos_set;
	Deal(){
		long long int g;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>g;
			pos_set.push_back(g);
		}
		sort(pos_set.begin(),pos_set.end());
	}
	bool judge(const long long int&min_dis){
		long long int num=1,pos_now=pos_set[0];
		for(long long int i=1;i<pos_set.size();i++){
			if(pos_set[i]-pos_now>=min_dis){
				num++;
				pos_now=pos_set[i];
				if(num>=m){
					return true;
				}
			}
		}
		return false;
	}
	void solve(){
		long long dis_min=pos_set[0];
		long long dis_max=pos_set[pos_set.size()-1]-pos_set[0];
		long long re;
		while(dis_min<=dis_max){
			long long mid=(dis_min+dis_max)/2;
			if(judge(mid)){//mid is enough,try to bigger it
				dis_min=mid+1;
				re=mid;
			}else{
				dis_max=mid-1;
				re=mid-1;
			}
		}
		cout<<re<<endl;
	}
};
int main(){
	Deal().solve();
}

```
## d
### 题目
#### 题目描述

小明喜欢玩平面魔方。平面魔方的每个小块都有一种颜色，一共有 8 种颜色，用 1-8 的数字表示。在初始时魔方的左上角小块的数字为 1，沿着顺时针方向依次编号，可以用一个 8 个数字的序列来表示魔方的状态。初始的序列为：`1 2 3 4 5 6 7 8`，对应的平面魔方如下：

`1 2 3 4 8 7 6 5`

你可以通过以下三种操作之一或多次操作，将一个初始状态变成目标状态：

+   A：交换魔方的上下两行；
+   B：将魔方最右边的一列插入到最左边；
+   C：魔方中央顺时针旋转 90 度。

下面是对初始状态进行操作的示范：

+   A：
    
    `8 7 6 5 1 2 3 4`
    
+   B：
    
    `4 1 2 3 5 8 7 6`
    
+   C：
    
    `1 7 2 4 8 6 3 5`
    

请你编写一个程序，计算出将初始状态转换为目标状态所需的最少操作数，并输出最短操作序列中字典序最小的一个。

#### 输入格式

输入仅一行，包括 8 个整数，用空格分隔，表示目标状态。

#### 输出格式

输出文件的第一行包括一个整数，表示最短操作序列的长度。 第二行为在字典序中最早出现的操作序列。

#### 数据范围与提示

输入数据中的所有数字均为 1 到 8 之间的整数。
### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
class Cube{
    public:
    string last_op_set="";
    vector<vector<int>>cube={{0,0,0,0},{0,0,0,0}};
    long long int sign=0;
    Cube(bool coo){
        for(int i=0;i<4;i++){
            cin>>cube[0][i];
        }
        for(int i=3;i>=0;i--){
            cin>>cube[1][i];
        }
        compute_sign();
    }
    Cube(){
        sign=0;
        cube={{1,2,3,4},{8,7,6,5}};
        for(int i=0;i<8;i++){
            sign=sign*10+cube[i/4][i%4];
        }
    }
    void compute_sign(){
        sign=0;
        for(int i=0;i<8;i++){
            sign=sign*10+cube[i/4][i%4];
        }
    }
    Cube op_A()const{
        Cube cube1;
        cube1.cube=cube;
        int g;
        for(int i=0;i<4;i++){
            g=cube1.cube[1][i];
            cube1.cube[1][i]=cube1.cube[0][i];
            cube1.cube[0][i]=g;
        }
        cube1.compute_sign();
        cube1.last_op_set=this->last_op_set;
        return cube1;
    }
    Cube op_B()const{
        Cube cube1;
        cube1.cube=cube;
        int a=cube[0][3],b=cube[1][3];
        int l_a,l_b;
        for(int i=0;i<4;i++){
            cube1.cube[0][i]=a;
            cube1.cube[1][i]=b;
            a=cube[0][i];
            b=cube[1][i];
        }
        cube1.compute_sign();
        cube1.last_op_set=this->last_op_set;
        return cube1;
    }
    Cube op_C()const{
        Cube cube1;
        cube1.cube=cube;
        int a=cube[0][1],b=cube[0][2],c=cube[1][1],d=cube[1][2];
        cube1.cube[0][1]=c;
        cube1.cube[0][2]=a;
        cube1.cube[1][1]=d;
        cube1.cube[1][2]=b;
        cube1.compute_sign();
        cube1.last_op_set=this->last_op_set;
        return cube1;
    }
    bool operator==(const Cube&other){
        return this->sign==other.sign;
    }
    bool operator <(const Cube&other){
        return last_op_set<other.last_op_set;
    }
    void out(){
        cout<<endl;
        for(int i=0;i<2;i++){
            for(int u=0;u<4;u++){
                cout<<cube[i][u]<<' ';
            }
            cout<<endl;
        }
    }
};
struct CompareCube{
       bool operator()(const Cube&thi,const Cube&other){
        return thi.last_op_set>other.last_op_set;
    } 
};
class Deal{
    public:
    Cube target_cube;
    Deal(){
        target_cube=Cube(0);
    }
    void bfs(){
        priority_queue<Cube,vector<Cube>,CompareCube>pq;
        int size=1;
        pq.push(Cube());
        if(Cube()==target_cube){
            cout<<0<<endl<<endl;
        }
        unordered_map<long long int,bool>_m;
        _m[pq.top().sign]=true;
        while(!pq.empty()){
            size=pq.size();
            vector<Cube>ttt;
            for(int i=0;i<size;i++){
                ttt.push_back(pq.top());
                pq.pop();
            }
            for(int i=0;i<ttt.size();i++){
                Cube tmp=ttt[i].op_A();
                tmp.compute_sign();
                if(_m.find(tmp.sign)==_m.end()){
                    _m[tmp.sign]=true;
                    tmp.last_op_set=tmp.last_op_set+"A";
                    if(tmp==target_cube){
                        cout<<tmp.last_op_set.size()<<endl;
                        cout<<tmp.last_op_set<<endl;
                        return;
                    }
                    pq.push(tmp);
                }
                tmp=ttt[i].op_B();
                tmp.compute_sign();
                if(_m.find(tmp.sign)==_m.end()){
                    _m[tmp.sign]=true;
                    tmp.last_op_set=tmp.last_op_set+"B";
                    if(tmp==target_cube){
                        cout<<tmp.last_op_set.size()<<endl;
                        cout<<tmp.last_op_set<<endl;
                        return;
                    }
                    pq.push(tmp);
                }
                tmp=ttt[i].op_C();
                tmp.compute_sign();
                if(_m.find(tmp.sign)==_m.end()){
                    _m[tmp.sign]=true;
                    tmp.last_op_set=tmp.last_op_set+"C";
                    if(tmp==target_cube){
                        cout<<tmp.last_op_set.size()<<endl;
                        cout<<tmp.last_op_set<<endl;
                        return;
                    }
                    pq.push(tmp);
                }
            }
        }
    }
    void solve(){
        bfs();
    }
};
int main(){
    Deal d=Deal();d.solve();
}
```
