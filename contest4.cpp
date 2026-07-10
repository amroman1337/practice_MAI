// C. Перестановка

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> res;

        for (int j = n; j >= k; j--) {
            res.push_back(j);
        }
        for (int j = m + 1; j < k; j++) {
            res.push_back(j);
        }
        for (int j = 1; j <= m; j++) {
            res.push_back(j);
        }
        for (int j = 0; j < n; j++) {
            cout << res[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}