#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	int MAX = 0;
	vector<int> cnt(1000001), pc(1000001), ps(1000001);
	for (auto &x : v) {
		cin >> x;
		MAX = max(MAX, x);
		cnt[x]++;
	}
	for (int i = 1;i <= MAX;i++) {
		pc[i] = pc[i - 1] + cnt[i];
		ps[i] = ps[i - 1] + cnt[i] * i;
	}
	while (q--) {
		int x;
		cin >> x;
		if (x > MAX) {
			cout << "-1\n";
			continue;
		}
		cout << max(0ll, ps[x - 1] + (x - 1) * (n - pc[x - 1])) + 1 << '\n';
	}
}

