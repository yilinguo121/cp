#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> p(m), y(m);
	vector<vector<int>> v(n + 1);
	for (int i = 0;i < m;i++) {
		cin >> p[i] >> y[i];
		v[p[i]].push_back(y[i]);
	}
	for (int i = 1;i <= n;i++) sort(v[i].begin(), v[i].end());
	for (int i = 0;i < m;i++) {
		printf("%06d%06ld\n", p[i], lower_bound(v[p[i]].begin(), v[p[i]].end(), y[i]) - v[p[i]].begin() + 1);
	}
}
