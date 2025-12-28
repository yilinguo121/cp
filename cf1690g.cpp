#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, m, now = 2e9;
		cin >> n >> m;
		vector<int> v(n + 1);
		map<int, int> mp;
		mp[0] = now;
		mp[n + 1] = -1;
		for (int i = 1;i <= n;i++) {
			cin >> v[i];
			if (v[i] < now) {
				mp[i] = v[i];
				now = v[i];
			}
		}
		while (m--) {
			int k, d;
			cin >> k >> d;
			v[k] -= d;
			auto it = mp.lower_bound(k);
			while (it->second >= v[k]) it = mp.erase(it);
			if (v[k] < prev(it)->second) mp[k] = v[k];
			cout << mp.size() - 2 << ' ';
		}
		cout << '\n';
	}
}
