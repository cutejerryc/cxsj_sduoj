#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int operations = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u = i + 1;
        while (u < n && a[u] - a[i] <= k) {
            ++u;
            if(u>i+1){
                break;
            }
        }
        operations += u - i - 1;
    }
    cout << operations << endl;
    return 0;
}
