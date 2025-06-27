#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int j = 0;j < m;j++) cin >> b[j];
	a[n] = 2e9, b[m] = 2e9;
	int pos_a = 0, pos_b = 0;
	long long ans = 0;
	while (pos_a < n or pos_b < m) {
		if (a[pos_a] < b[pos_b]) pos_a++;
		else if (b[pos_b] < a[pos_a]) pos_b++;
		else {
			int x = 0, y = 0, k = a[pos_a];
			while (a[pos_a] == k) {
				pos_a++;
				x++;
			}
			while (b[pos_b] == k) {
				pos_b++;
				y++;
			}
			ans += 1ll * x * y;
		}
	}
	cout << ans;
}
