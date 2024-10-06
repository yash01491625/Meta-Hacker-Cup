#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("output.txt", "w", stdout); 
    #endif 
    int tc = 1;
    int tt;
    cin >> tt;
    while (tt--) {  
        int n, k;
        cin >> n >> k;
        vector<int> s(n);
        int mn = 1e9;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            mn = min(mn, s[i]);
        }
        cout << "Case #" << tc++ << ": ";
        if(n == 1) {
            cout << (mn <= k ? "YES\n" : "NO\n");
        } else {
            cout << (mn * (2 * n - 3) <= k ? "YES\n" : "NO\n");
        }
    }
    return 0;
}