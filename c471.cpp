#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.f * b.s < a.s * b.f;
}
signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].f;
	}
	for (int i = 0;i < n;i++) {
		cin >> v[i].s;
	}

	sort(v.begin(), v.end(), cmp);
	int now = v[0].f, ans = 0;
	for (int i = 1;i < n;i++) {
		ans = ans + (now * v[i].s);
		now += v[i].f;
	}
	cout << ans << '\n';
}
