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
        long double n, p;
        cin >> n >> p;
        cout << "Case #" << tc++ << ": ";
        cout << setprecision(18) << (p * pow((long double)(100 / p), (long double)1 / n)) - p << "\n";
    }
    return 0;
}