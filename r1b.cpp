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
    const int mx = 1e7;
    vector<bool> primes(mx + 1, true);
    primes[0] = primes[1] = false;
    for(int i = 2; i * i <= mx; i++) {
        if(primes[i]) {
            for(int j = i * i; j <= mx; j += i) {
                primes[j] = false;
            }
        }
    }
    int tt = 1;
    cin >> tt;
    for(int qq = 1; qq <= tt; qq++) {
        cout << "Case #" << qq << ": ";
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 2; i <= n; i++) {
            if(primes[i] && primes[i - 2]) {
                ans += 1;
            }
        }
        if(n >= 5) ans += 1;
        cout << ans << "\n";
    }
    return 0;
}