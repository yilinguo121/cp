#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v;
		for (int i = 0;i < n;i++) {
			char x;
			cin >> x;
			if (x == '*') v.push_back(i);
		}
		if (v.empty()) {
			cout << "0\n";
			continue;
		}
		int ans = 1, now = v[0];
		while (now < v[v.size() - 1]) {
			ans++;
			now = *--upper_bound(v.begin(), v.end(), now + k);
		}
		cout << ans << '\n';
	}
}

