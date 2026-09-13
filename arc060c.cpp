#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, l;
	cin >> n;
	vector<int> v(n), nxt(n);
	for (auto &x : v) cin >> x;
	cin >> l;
	for (int i = 0;i < n;i++) {
		int j = i;
		while (j + 1 < n and v[j + 1] - v[i] <= l) j++;
		nxt[i] = j;
	}
	vector<vector<int>> st(n, vector<int>(18));
	for (int i = 0;i < n;i++) st[i][0] = nxt[i];
	for (int j = 1;j < 18;j++) for (int i = 0;i < n;i++) st[i][j] = st[st[i][j - 1]][j - 1];
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a > b) swap(a, b);
		int ans = 0, now = a;
		for (int j = 17;j >= 0;j--) if (st[now][j] < b) {
			now = st[now][j];
			ans += (1 << j);
		}
		cout << ans + 1 << '\n';
	}
}
