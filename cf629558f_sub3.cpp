#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[end, start] : v) cin >> start >> end;
	sort(v.begin(), v.end());
	int ans = 0, now = 0;
	for (auto &[end, start] : v) {
		if (start >= now) {
			ans++;
			now = end;
		}
	}
	cout << ans;
}

