#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0, j = 0;i < n;i++) {
		while (j < n and v[i] >= v[j]) j++;
		if (j == n) break;
		ans++;
		j++;
	}
	cout << ans;
}
