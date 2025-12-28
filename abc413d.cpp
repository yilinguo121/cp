#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
signed main() {
	int t;
	cin >> t;
	while (t--) {
		bool flag1 = 0, flag2 = 0;
		int n;
		cin >> n;
		vector<int> v(n);
		deque<int> q;
		for (auto &x : v) {
			cin >> x;
			if (x < 0) flag1 = 1;
			if (x > 0) flag2 = 1;
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (auto x : v) q.push_back(x);
		vector<int> a;
		if (flag1 and flag2) {
			while (!q.empty()) {
				if (abs(q.front()) > abs(q.back())) {
					a.push_back(q.front());
					q.pop_front();
				}
				else {
					a.push_back(q.back());
					q.pop_back();
				}
			}
		}
		else {
			a.resize(n);
			for (int i = 0;i < n;i++) a[i] = v[i];
		}
		bool ans = 1;
		for (int i = 1;i < n - 1;i++) {
			if (a[i - 1] * a[i + 1] != a[i] * a[i]) ans = 0;
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
}
