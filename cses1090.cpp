#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int ans = 0;
	int j = n - 1, i = 0;
	while (i <= j) {
		int cnt = v[j];
		if (i < j and cnt + v[i] <= x) {
			cnt += v[i];
			i++;
		}
		ans++;
		j--;
	}
	cout << ans;
}

