#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1), a(m + 1);
	for (int i = 1;i <= m;i++) {
		cin >> a[i];
	}
	for (int i = 1;i < m;i++) {
		int s = min(a[i], a[i + 1]);
		int b = max(a[i], a[i + 1]);
		int q = b - s;
		int p = n - q;
		if (s > 1) {
			v[1] += q;
			v[s] -= q;
		}
		v[s] += p;
		v[b] -= p;
		v[b] += q;
	}
	int ans = 1e15;
	for (int i = 1;i <= n;i++) {
		v[i] += v[i - 1];
		ans = min(v[i], ans);
	}
	cout << ans;
}
