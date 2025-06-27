#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int n, m;
vector<int> f(int x) {
	vector<int> v;
	for (int i = 1;i * i <= x;i++) {
		if (x % i == 0) {
			if (i <= m) v.push_back(i);
			int j = x / i;
			if (j != i and j <= m) v.push_back(j);
		}
	}
	return v;
}
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> v(n);
		vector<vector<int>> a(n);
		for (int i = 0;i < n;i++) cin >> v[i];
		sort(v.begin(), v.end());
		for (int i = 0;i < n;i++) a[i] = f(v[i]);
		int ans = 1e8, cnt = 0;
		map<int, int> mp;
		for (int i = 0, j = 0;i < n;i++) {
			for (auto x : a[i]) {
				if (!mp[x]) cnt++;
				mp[x]++;
			}
			while (cnt >= m and j <= i) {
				ans = min(ans, v[i] - v[j]);
				for (auto x : a[j]) {
					mp[x]--;
					if (!mp[x]) cnt--;
				}
				j++;
			}
		}
		cout << (ans == 1e8 ? -1 : ans) << '\n';
	}
}

