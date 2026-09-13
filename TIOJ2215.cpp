#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> up;
vector<int> deep;
int lca(int a, int b) {
	if (deep[a] < deep[b]) swap(a, b);
	for (int i = 0;i < 20;i++) if (((deep[a] - deep[b]) >> i) & 1) a = up[a][i];
	if (a == b) return a;
	for (int i = 19;i >= 0;i--) if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
	return up[a][0];
}
int dis(int a, int b) {
	int x = lca(a, b);
	return deep[a] - deep[x] + deep[b] - deep[x];
}
int main() {
	IO
	int n;
	cin >> n;
	deep.resize(n + 1);
	up.resize(n + 1, vector<int>(20));
	int a = 1, b = 1, ans = 0;
	for (int i = 2;i <= n;i++) {
		int p;
		cin >> p;
		up[i][0] = p;
		deep[i] = deep[p] + 1;
		for (int j = 1;j < 20;j++) up[i][j] = up[up[i][j - 1]][j - 1];
		int da = dis(i, a), db = dis(i, b);
		if (da > ans or db > ans) {
			if (da > db) ans = da, b = i;
			else ans = db, a = i;
		}
		cout << ans << '\n';
	}
}
