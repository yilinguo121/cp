#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0;i < n;i++) cin >> v[i];
		vector<int> a(v);
		sort(a.begin(), a.end());
		a.resize(unique(a.begin(), a.end()) - a.begin());
		for (int i = 0;i < n;i++) {
			cout << lower_bound(a.begin(), a.end(), v[i]) - a.begin() + 1 << ' ';
		}
		cout << '\n';
	}
}

