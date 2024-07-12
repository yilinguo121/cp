#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].f;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].s;
	}
	sort(v.begin(), v.end());
	int now = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		now += v[i].f;
		ans = ans + (v[i].s - now);
	}
	cout << ans << '\n';
}
