// C. Кракен и корабли

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll total = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }
        if (k >= total) {
            cout << n << endl;
            continue;
        }
        
        ll l_attacks = (k + 1) / 2;
        ll r_attacks = k / 2;
        int dead = 0;
        int l = 0;
        while (l < n && l_attacks >= a[l]) {
            l_attacks -= a[l];
            dead++;
            l++;
        }
        if (l < n && l_attacks > 0) {
            a[l] -= l_attacks;
        }
        
        int r = n - 1;
        while (r >= 0 && r_attacks >= a[r]) {
            r_attacks -= a[r];
            dead++;
            r--;
        }
        cout << dead << endl;
    }
    return 0;
}