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
