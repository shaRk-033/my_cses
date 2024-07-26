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
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; v.push_back(x);
    }
    vector<long long> dp(sum + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - v[j]]);
            }
        }
    }
    if (dp[sum] == INT_MAX) {printf("%d", -1);}
    else {
        printf("%ld", dp[sum]);
    }
    return 0;
}
