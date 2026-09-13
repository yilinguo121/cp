#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const long long mod = 998244353;
int f(int x, int y) {
	int res = 1;
	for (;y;y /= 2, x = x * x % mod) if (y % 2) res = res * x % mod;
	return res;
}
signed main() {
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	vector<int> cnt(n + 1);
	for (int i = 1;i <= n;i++) for (int j = i;j <= n;j += i) cnt[j]++;
	int ans = 0, win = (p % mod * f(q, mod - 2)) % mod, inv = f(n, mod - 2);
	for (int i = 1;i <= n;i++) ans = (ans + (1 - f((n - cnt[i]) * inv % mod, m) + mod) % mod * win) % mod;
	cout << ans;
}
