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
