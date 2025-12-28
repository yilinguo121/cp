#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	if ((n * (n + 1)) / 2 % 2) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int cnt = (n * (n + 1)) / 4;
	vector<int> a, b;
	for (int i = n;i >= 1;i--) {
		if (i <= cnt) {
			a.push_back(i);
			cnt -= i;
		}
		else b.push_back(i);
	}
	cout << a.size() << '\n';
	for (auto x : a) cout << x << ' ';
	cout << '\n' << b.size() << '\n';
	for (auto x : b) cout << x << ' ';
}

