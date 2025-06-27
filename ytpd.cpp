#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1), ans(n + 1);
	for (int i = 1;i <= n;i++) v[i] = i;
	vector<int> x(k + 1), y(k + 1);
	int pos;
	for (int i = 1;i <= k;i++) {
		cin >> x[i] >> y[i];
		if (x[i] == -1) pos = i;
	}
	for (int i = 1;i <= n;i++) cin >> ans[i];
	for (int i = k;i > pos;i--) swap(ans[x[i]], ans[y[i]]);
	for (int i = 1;i < pos;i++) swap(v[x[i]], v[y[i]]);
	for (int i = 1;i <= n;i++) if (ans[i] != v[i]) cout << i << ' ';
}

