#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int r=0,g=0,b=0;
    for(int i=0;i<s.size();i++){
        switch (s[i])
        {
        case 'R':
            r++;
            break;
        case 'G':
            g++;
            break;
        case 'B':
            b++;
            break;
        default:
            break;
        }
    }
    cout << ((r < b && r < g) ? r : (b < r && b < g ? b : g)) << endl;

}