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
