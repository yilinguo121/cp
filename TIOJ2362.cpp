#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int m, n;
	cin >> m >> n;
	int t, k, r;
	cin >> t >> k >> r;
	vector<pair<int, int>> v;
	while (t--) {
		int c;
		cin >> c;
		v.push_back({max(c - k + 1, 1ll), 1});
		v.push_back({min(c, n - k + 1) + 1, -1});
	}
	int a = 0;
	int b = min(r, m - k + 1) - max(1ll, r - k + 1) + 1;
	int cnt = 1;
	sort(v.begin(), v.end());
	for (int i = 1;i < v.size();i++) {
		if (cnt % 2) a += (v[i].first - v[i - 1].first) * b;
		cnt += v[i].second;
	}
	if (k % 2) {
		cout << (n - k + 1) * (m - k + 1) - a;
	}
	else {
		cout << a;
	}

}

