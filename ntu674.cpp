#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	priority_queue<int> q;
	int ans = 1e9;
	for (int i = 0, j = 0;i < n;i++) {
		while (j < n and v[j].first <= v[i].first) {
			q.push(v[j].second);
			if ((int)q.size() > k) q.pop();
			j++;
		}
		if (q.size() == k) ans = min(ans, v[i].first + q.top());
	}
	cout << ans << '\n';
}
