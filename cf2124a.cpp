#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		while (!v.empty()) {
			vector<int> b;
			auto a = v;
			sort(a.begin(), a.end());
			bool flag = 1;
			for (int i = 0;i < v.size();i++) {
				if (a[i] == v[i] and flag) {
					flag = 0;
					continue;
				}
				b.push_back(v[i]);
			}
			v = b;
			if (flag) {
				cout << "YES\n" << v.size() << '\n';
				for (auto x : v) cout << x << ' ';
				cout << '\n';
				break;
			}
		}
		if (v.empty()) cout << "NO\n";
	}
}
