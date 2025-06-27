#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	int m = n;
	int g;
	cin >> g;
	int p = 0;
	vector<int> a(n);
	for (int i = 1;i <= g;i++) {
		int t;
		cin >> t;
		t--;
		v[t] -= n * i;
		p += i;
		if (v[t] + p < 0) {
			n--;
			a[t] = p;
		}
	}
	for (int i = 0;i < m;i++) {
		if (a[i] != 0) cout << 1ll * v[i] + a[i] << ' ';
		else cout << 1ll * v[i] + p << ' ';
	}
}

