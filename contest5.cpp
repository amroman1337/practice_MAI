// C. Инвестиции

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> c(n, vector<int>(m + 1, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c[i][j];
            }
        }
        
        vector<int> prev_dp(m + 1, 0);
        
        for (int i = 0; i < n; i++) {
            vector<int> cur_dp(m + 1, 0);
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= j; k++) {
                    cur_dp[j] = max(cur_dp[j], prev_dp[j - k] + c[i][k]);
                }
            }
            swap(prev_dp, cur_dp);
        }
        cout << prev_dp[m] << endl;
    }
    return 0;
}