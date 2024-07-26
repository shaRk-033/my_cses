#include <bits/stdc++.h>
using namespace std;
 
// void solve(int i, int j, vector<vector<char>> v, int& ans) {
//     if (i == v.size() - 1 && j == v.size() - 1) {
//         ans++;
//         return;
//     }
//     if (i == v.size() || j == v.size() || v[i][j] == '*') {
//         return;
//     }
//     solve(i + 1, j, v, ans);
//     solve(i, j + 1, v, ans);
// }
 
int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n; cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            v[i][j] = c;
        }
    }
    int ans = 0, mod = 1e9 + 7;
    vector<vector<long long >> dp(n, vector<long long>(n, 0));
    if (v[0][0] == '*') {
        printf("%d", 0);
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != '*') {
                long long x = 0, y = 0;
                if (i - 1 >= 0) {
                    x = dp[i - 1][j];
                }
                if (j - 1 >= 0) {
                    y = dp[i][j - 1];
                }
                dp[i][j] += (x + y) % mod;
            }
        }
    }
    printf("%lld", dp[n - 1][n - 1]);
    return 0;
}
