// D. Планы рассадки

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    
    ll max_mask = (1 << n);
    vector<vector<ll>> dp(max_mask, vector<ll>(n, 0));
    
    for (ll i = 0; i < n; i++) {
        dp[1 << i][i] = 1;
    }
    
    for (ll mask = 1; mask < max_mask; mask++) {
        for (ll last = 0; last < n; last++) {
            if (dp[mask][last] == 0) {
                continue;
            }
            for (ll next = 0; next < n; next++) {
                if (mask & (1 << next)) {
                    continue;
                }
                if (a[last][next] == 0) {
                    continue;
                }
                dp[mask | (1 << next)][next] += dp[mask][last];
            }
        }
    }
    ll ans = 0;
    ll fullMask = max_mask - 1;
    for (ll last = 0; last < n; last++) {
        ans += dp[fullMask][last];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    
    return 0;
}