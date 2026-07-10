// E. Преобразуй число

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    vector<long long> res(n + 1, 0);
    res[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        res[i] = res[i - 1] + i;
        if (i % 2 == 0) {
            res[i] = min(res[i], res[i/2] + i);
        }
        if (i % 3 == 0) {
            res[i] = min(res[i], res[i/3] + i);
        }
    }
    cout << res[n] << endl;
    return 0;
}