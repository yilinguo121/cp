#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> p;
int f(int a, int b) {
	return p[b] - p[a - 1];
}
signed main() {
	int n, k;
	cin >> n >> k;
	p.assign(n + 1, 0);
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) p[i + 1] = p[i] + v[i];
	int MIN = 1e18, ans = 1e18;
	int h = k / 2;
	for (int i = k;i + k <= n;i++) {
		MIN = min(MIN, f(i - h + 1,i) - f(i - k + 1, i - k + h));
		ans = min(ans, MIN + f(i - h + k + 1, i + k) - f(i + 1, i + h));
	}
	cout << ans;
}

