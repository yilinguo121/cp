#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	for (int i = 0;i < n;i++) cin >> a[i];
	a[n] = 2e9;
	b[m] = 2e9;
	for (int j = 0;j < m;j++) cin >> b[j];
	int pos_a = 0, pos_b = 0;
	vector<int> v;
	while (pos_a < n or pos_b < m) {
		if (a[pos_a] < b[pos_b]) {
			v.push_back(a[pos_a]);
			pos_a++;
		}
		else {
			v.push_back(b[pos_b]);
			pos_b++;
		}
	}
	for (auto x : v) cout << x << ' ';
}

