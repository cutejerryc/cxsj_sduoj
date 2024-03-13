# 山东大学程序设计思维与实践作业-Week3
**仅作参考，切莫照搬，有查重**
- 代码题目
  - 1
  ```shell
  git clone https://github.com/W1412X/cxsj_sduoj.git
  ```
  - 2  
前往https://github.com/W1412X/cxsj_sduoj.git获取

- 简答题目
# 1
- 1
  - 在BFS中存储待遍历的节点时使用队列，利用其先进先出的特性
  - 在BFS中节点有权重时可以通过优先队列来最快的找到最优解，可以按照节点的权重来进行遍历
- 2 
  - 优先队列在插入时需要按顺序插入，时间复杂度相比于队列更高

# 2
在DFS进行搜索的过程中可以通过剪支进行对一些已经可以判定不存在解的情况进行排除
# 3
- 解法
  - 对输入的数列进行遍历，用一个整数记录上一次跳的分数
  - 根据上一次的分数来判断这一次应该的多少分
  - 同时更新这个分数
- 时间复杂度
$$
O(n)
$$
  - 解释
    - 遍历数列，为O(n)
- 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	int last_point=0;
	int sum=0;
	int p;
	while(1){
		cin>>p;
		if(p==0){
			cout<<sum<<endl;
			break;
		}
		if(p==1){
			sum+=1;
			last_point=0;
		}
		if(p==2){
			sum+=last_point+2;
			last_point+=2;
		}
	}
}

```
# 4
- 解法
  - 采用递归，从初始层开始，计算其可以到达的楼层，并将这些楼层存入队列(标记已经存入过队列的楼层，防止重复添加)
  - 同时将本层移出队列
  - 循环往复，直至到达指定楼层或者队列为空
- 时间复杂度
$$
O(n)
$$
  -解释: 对于每个楼层，仅去一次，所以时间复杂度为O(n)
- 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
int n;
void deal(int n){
	int a,b;
	std::cin>>a>>b;
	vector<bool>if_appear(n+1,false);
	vector<int>floor(n+1);
	for(int i=1;i<=n;i++){
		cin>>floor[i];
	}
	queue<int>f;
	int times=0;
	if(a==b){//if already in the floor
		cout<<0<<endl;
		return;
	}
	if_appear[a]=true;
	f.push(a);
	bool if_find=false;
	int f_size=f.size();
	while(f.size()>0){//
		times+=1;
		for(int i=f_size;i>0;i--){
			int down=f.front()-floor[f.front()]>0?f.front()-floor[f.front()]:-1;
			int up=f.front()+floor[f.front()]<=n?f.front()+floor[f.front()]:-1;
			if(down==b||up==b){
				if_find=true;
				break;
			}
			if(down!=-1&&!if_appear[down]){
				if_appear[down]=true;
				f.push(down);
			}
			if(up!=-1&&!if_appear[up]){
				if_appear[up]=true;
				f.push(up);
			}
			f.pop();
		}
		if(if_find){
			break;
		}
		f_size=f.size();
	}             
	if(if_find){
		cout<<times<<endl;
	}else{
		cout<<-1<<endl;
	}
}
int main(){
	while(1){
		cin>>n;
		if(n!=0){
			deal(n);
		}else{{
			break;
		}}
	}
}
```