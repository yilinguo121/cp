#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long ans = 0;
	for (int i = 0;i < n;i++) ans += abs(a[i] - b[i]);
	cout << ans;
}
