// D. 76-я задача на OEIS

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    vector<int> primes;
    int num = 2;
    while (primes.size() < 10005) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            long long val = 1LL * primes[i] * primes[i + 1];
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}