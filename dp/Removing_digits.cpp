#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int x; cin >> x;
    vector<long long> dp(x + 1, INT_MAX);
    int mod = 1e9 + 7;
    dp[x] = 0;
    for (int i = x; i >= 0; i--) {
        string s = to_string(i);
        long long temp = INT_MAX;
        for (auto it : s) {
            if (i >= (it) - '0') {
                dp[i - (it - '0')] = min((1 + dp[i]) % mod, dp[i - (it - '0')]);
            }
        }
    }
    printf("%ld", dp[0]);
 
    return 0;
}
