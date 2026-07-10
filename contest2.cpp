// D. Количество различных подстрок

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()
 
void z_func(string z, vector<int>& dt) {
    int n = z.size();
    dt.resize(n);
    fill(all(dt), 0);
    int l = 0, r = 0;
    dt[0] = n;
    for (int i = 1; i < n; ++i) {
        if (i <= r){
            dt[i] = min(r - i + 1, dt[i - l]);
        }
        while (i + dt[i] < n && z[dt[i]] == z[i + dt[i]]) {
            ++dt[i];
        }
        if (i + dt[i] - 1 > r) {
            r = i + dt[i] - 1;
            l = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int n = s.length();
    int res = 0;
    string cur = "";
    
    for (int i = n - 1; i >= 0; i--) {
        cur = s[i] + cur;
        vector<int> z;
        z_func(cur, z);
        int mx = 0;
        int size_z = z.size();
        for (int j = 1; j < size_z; j++) {
            mx = max(mx, z[j]);
        }
        res += cur.length() - mx;
    }
    cout << res << endl;
    return 0;
}