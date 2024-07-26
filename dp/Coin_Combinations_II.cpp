#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n, sum;
    cin >> n >> sum;
    std::vector<long long > v;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x; v.push_back(x);
    }
    int mod = 1e9 + 7;
    vector<long long> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (v[i] <= j) {
                dp[j] += (dp[j - v[i]]) % mod;
            }
        }
    }
 
    dp[sum] %= mod;
 
    printf("%ld", dp[sum]);
 
    return 0;
}
