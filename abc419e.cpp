#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}
	vector<int> a(n + 1);
	int ans = 0, now = 0;
	for (int i = 1;i + l - 1 <= n;i++) {
		int j = i + l - 1;
		int sum = v[j] - v[i - 1];
		int add = (m - (sum + now) % m) % m;
		a[j] = add;
		ans += add;
		now += add;
		now -= a[i];
	}
	cout << ans;
}
