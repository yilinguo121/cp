#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int f[n] = {};
	vector<string> s(n);
	for (int i = 0;i < n;i++) {
		cin >> s[i];
		for (int j = 0;j < m;j++) {
			f[i] |= ((s[i][j] == 'o') << j);
		}
	}
	int all = (1 << m) - 1;
	int ans = 1e9;
	for (int i = 1;i < (1 << n);i++) {
		int t = 0;
		int count = 0;
		for (int j = 0;j < n;j++) {
			if (i & (1 << j)) {
				t |= f[j];
				count++;
			}
		}
		if (t == all) {
			ans = min(ans, count);
		}
	}
	cout << ans;
}
