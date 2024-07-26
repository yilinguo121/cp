#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.f == b.f) {
		return a.s < b.s;
	}
	return a.f < b.f;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].f >> v[i].s;
	}
	sort(v.begin(), v.end(), cmp);
	int t = v[0].s;
	int ans = v[0].s - v[0].f;
	for (int i = 1;i < n;i++) {
		if (v[i].f <= t and v[i].s >= t) {
			ans += v[i].s - t;
			t = v[i].s;
		}
		if (v[i].f > t) {
			ans += v[i].s - v[i].f;
			t = v[i].s;
		}
	}
	cout << ans << '\n';
}
