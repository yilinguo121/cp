#include <bits/stdc++.h>
using namespace std;
int n, m;
bool cmp(vector<int> a, vector<int> b) {
	for (int i = 0;i < m;i++) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> v;
	for (int i = 0;i < n;i++) {
		vector<int> t(m);
		for (int j = 0;j < m;j++) cin >> t[j];
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

