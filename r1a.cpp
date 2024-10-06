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
    int tt = 1;
    cin >> tt;
    for(int qq = 1; qq <= tt; qq++) {
        cout << "Case #" << qq << ": ";
        int n;
        cin >> n;
        vector<pair<long double, long double>> s(n);
        for(int i = 0; i < n; i++) {
            cin >> s[i].first >> s[i].second;
        }
        auto ok = [&](long double speed) -> bool {
            for(int i = 0; i < n; i++) {
                long double time = (i + 1) / speed;
                if(time > s[i].second) return false;
                if(time < s[i].first) return true;
            }
            return true;
        };
        long double l = 0, r = n;
        int iter = 0, mx = 100;
        while((r - l) > 1e-14 && iter <= mx) {
            long double m = (l + (r - l) / 2);
            if(ok(m)) {
                r = m;
            } else {
                l = m;
            }
            iter += 1;
        }
        const long double ep = 1e-7;
        for(int i = 0; i < n; i++) {
            long double time = (i + 1) / r;
            if(time < s[i].first - ep || time > s[i].second + ep) {
                r = -1;
                break;
            }
        }
        cout << setprecision(20) << r << "\n";
    }
    return 0;
}

/*
2nd Method (adjust the slope)
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
    int tt = 1;
    cin >> tt;
    for(int qq = 1; qq <= tt; qq++) {
        cout << "Case #" << qq << ": ";
        int n;
        cin >> n;
        vector<pair<long double, long double>> s(n);
        for(int i = 0; i < n; i++) {
            cin >> s[i].first >> s[i].second;
        }
        long double mn = INT64_MAX, mx = INT64_MIN;
        for(int i = 0; i < n; i++) {
            mx = max(mx, (i + 1) / s[i].second);
            mn = min(mn, (i + 1) / s[i].first);
        }
        if(mx > mn) {
            cout << "-1\n";
        } else {
            cout << setprecision(20) << mx << "\n";    
        }
    }
    return 0;
}
*/
