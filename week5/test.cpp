#include<bits/stdc++.h>
using namespace std;

int n,m,l,x,c;
long long b;
int prime_no[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
long long qpower(long long a,long long b,long long m){
    long long result=1;
    if(!b) 
        return 1;
    while(b>0){
        if(b&1) 
            result=result*a%m;
        a=a*a%m;
        b=b>>1;
    }
    return result;
}

int main()
{
	cin>>n>>m;
	long long a[n+1][25]={0};
	for(int i=0;i<m;i++)
	{
		cin>>l>>x>>c>>b;
		for(int j=0;j<25;j++)
		{
			if(c<prime_no[j]) break;
			else{
				while(c%prime_no[j]==0)
				{
					a[l][j]+=b;
					a[x+1][j]-=b;
					c/=prime_no[j];
				}
			}
		}
	}
	long long minno[25]={0};
	for(int i=0;i<25;i++)
	{
		minno[i]=a[1][i];
	}
	
	for(int i=0;i<25;i++)
	{
		for(int j=2;j<=n;j++)
		{
			a[j][i]+=a[j-1][i];
			minno[i]=min(a[j][i],minno[i]);
		}
	}
	long long m = 1e9+7;
    long long result = 1;
    for(int i = 0; i < 25; i++){
        result = result * qpower(prime_no[i],minno[i],m) % m;
    }
    cout<<result<<endl;

	
	return 0;
}
