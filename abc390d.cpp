#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
unordered_set<int> st;
vector<int> v, a;
int n;
void dfs(int i, int now, int m) {
	if (i == n) {
		st.insert(now);
		return;
	}
	a[m] = v[i];
	dfs(i + 1, now ^ v[i], m + 1);
	a[m] = 0;
	for (int j = 0;j < m;j++) {
		int old = a[j];
		a[j] += v[i];
		dfs(i + 1, now ^ old ^ (a[j]), m);
		a[j] -= v[i];
	}
}
signed main() {
	cin >> n;
	v.resize(n);
	a.resize(n);
	for (auto &x : v) cin >> x;
	dfs(0, 0, 0);
	cout << st.size();
}

