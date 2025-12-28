#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<int> v(n + 1), pre(n + 1);
		for (int i = 1;i <= n;i++) cin >> v[i];
		for (int i = 2;i < n;i++) if (v[i - 1] > v[i] and v[i] > v[i + 1]) pre[i]++;
		for (int i = 1;i <= n;i++) pre[i] += pre[i - 1];
		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << (pre[r] - pre[l - 1] ? "NO\n" : "YES\n");
		}
	}
}

