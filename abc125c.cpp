#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	vector<int> a(n), b(n);
	for (int i = 0;i < n - 1;i++) a[i + 1] = gcd(v[i], a[i]);
	for (int i = n - 2;i >= 0;i--) b[i] = gcd(v[i + 1], b[i + 1]);
	int ans = 0;
	for (int i = 0;i < n;i++) ans = max(ans, gcd(a[i], b[i]));
	cout << ans << '\n';
}

