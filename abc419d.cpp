#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	vector<int> v(n);
	while (m--) {
		int l, r;
		cin >> l >> r;
		v[l - 1]++;
		v[r]--;
	}
	for (int i = 1;i < n;i++) v[i] += v[i - 1];
	for (int i = 0;i < n;i++) {
		if (v[i] % 2) cout << t[i];
		else cout << s[i];
	}
}

