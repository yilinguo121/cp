#include <bits/stdc++.h>
using namespace std;
vector<int> x[100001], y[100001];
long long f(vector<int> v) {
	int n = v.size();
	long long k = 0;
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) {
		k += v[i] * (i * 2 - n + 1ll);
	}
	return k;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			int t;
			cin >> t;
			x[t].push_back(i);
			y[t].push_back(j);
		}
	}
	long long ans = 0;
	for (int i = 1;i <= 100000;i++) {
		ans += f(x[i]);
		ans += f(y[i]);
	}
	cout << ans;
}

