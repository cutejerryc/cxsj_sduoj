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