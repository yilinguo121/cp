#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	string s;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> s;
		for (int j = 0;j < m;j++) {
			if (s[j] == 'o') v[i] |= (1 << j);
		}
	}
	int t = (1 << m) - 1;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			if ((v[i] | v[j]) == t) ans++;
		}
	}
	cout << ans;
}

