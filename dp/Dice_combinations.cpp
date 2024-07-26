#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6;
const int MOD = 1e9 + 7;
#define REP(i, n) for (ll i = 0; i < n; ++i)

int dp[maxN + 1];
int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n; cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 6 && i - j >= 0; j++)
		{
			dp[i] = (dp[i] + dp[i - j]) % MOD;
		}
	}
	cout << dp[n];
 
}
