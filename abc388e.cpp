#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v(n / 2);
	for (auto &x : v) cin >> x;
	int ans = 0;
	for (int i = n / 2, j = 0;i < n;i++) {
		int x;
		cin >> x;
		if (j < n / 2 and v[j] * 2 <= x) {
			ans++;
			j++;
		}
	}
	cout << ans;
}
