#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	vector<int> l(m), r(m);
	for (int i = 0, j = 0;i < m;i++) {
		while (t[i] != s[j]) j++;
		l[i] = j;
		j++;
	}
	for (int i = m - 1,j = n - 1;i >= 0;i--) {
		while (t[i] != s[j]) j--;
		r[i] = j;
		j--;
	}
	int ans = 0;
	for (int i = 0;i < m - 1;i++) ans = max(ans, r[i + 1] - l[i]);
	cout << ans;
}
