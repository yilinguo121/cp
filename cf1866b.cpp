#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int mod = 998244353;
int main() {
	IO
	int n, m;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int j = 0;j < n;j++) cin >> b[j];
	cin >> m;
	vector<int> c(m), d(m);
	for (int i = 0;i < m;i++) cin >> c[i];
	for (int j = 0;j < m;j++) cin >> d[j];
	int i = 0, j = 0;
	long long ans = 1;
	while (i < n or j < m) {
		if (j >= m or (i < n and a[i] < c[j])) {
			i++;
			ans = (ans * 2) % mod;
		}
		else if (i >= n or (j < m and a[i] > c[j])) {
			cout << 0;
			return 0;
		}
		else {
			if (b[i] < d[j]) {
				cout << 0;
				return 0;
			}
			if (b[i] > d[j]) ans = (ans * 2) % mod;
			i++;
			j++;
		}
	}
	cout << ans;
}
