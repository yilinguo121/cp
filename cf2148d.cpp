#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0, sum = 0;
		vector<int> v;
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			if (x % 2) v.push_back(x);
			else sum += x;
		}
		sort(v.begin(), v.end());
		int l = 0, r = v.size() - 1;
		while (l <= r) {
			ans += v[r];
			r--;
			l++;
		}
		cout << (ans ? ans + sum : 0) << '\n';
	}
}
