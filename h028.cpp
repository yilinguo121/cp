#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, l;
	cin >> n >> l;
	vector<int> v, pos(n), h(n);
	for (int i = 0;i < n;i++) cin >> pos[i];
	for (int i = 0;i < n;i++) cin >> h[i];
	int ans = 0, cnt = 0;
	for (int i = 0;i < n;i++) {
		v.push_back(i);
		while (v.size() > 1 and pos[v[v.size() - 2]] + h[v[v.size() - 2]] <= pos[v[v.size() - 1]]) {
			cnt++;
			ans = max(ans, h[v[v.size() - 2]]);
			v.erase(v.end() - 2);
		}
		while (v.size() > 1 and pos[v[v.size() - 1]] - h[v[v.size() - 1]] >= pos[v[v.size() - 2]]) {
			cnt++;
			ans = max(ans, h[v[v.size() - 1]]);
			v.pop_back();
		}
	}
	while (v.size() > 0 and pos[v[0]] - h[v[0]] >= 0) {
		cnt++;
		ans = max(ans, h[v[0]]);
		v.erase(v.begin());
	}
	while (v.size() > 0 and pos[v[v.size() - 1]] + h[v[v.size() - 1]] <= l) {
		cnt++;
		ans = max(ans, h[v[v.size() - 1]]);
		v.pop_back();
	}
	cout << cnt << '\n' << ans;
}
