#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, m;
string s, t;
void f(int k) {
	bool flag = 1;
	for (int i = 0;i < m;i++) {
		if (s[k + i] != '#' and s[k + i] != t[i]) return;
		if (s[k + i] != '#') flag = 0;
	}
	if (flag) return;
	for (int i = 0;i < m;i++) s[k + i] = '#';
	for (int i = max(0, k - m + 1);i <= k and i + m <= n;i++) f(i);
}
int main() {
	cin >> n >> m >> s >> t;
	for (int i = 0;i + m <= n;i++) f(i);
	cout << (s == string(n, '#') ? "Yes" : "No");
}
