#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<int> pos(n + 1, -1);
	vector<pair<int, int>> v;
	for (int i = 0;i < 2 * n;i++) {
		int x;
		cin >> x;
		if (pos[x] >= 0) v.push_back({pos[x], i});
		else pos[x] = i;
	}
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.second < b.second;
	});
	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (auto [l, r] : v) {
		while (!q.empty() and q.top() < l) q.pop();
		if (q.size() < 2) {
			q.push(r);
			ans++;
		}
	}
	cout << ans;
}
