#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0, i = 0;;
	for (auto x : b) {
		while (a[i] <= x and i < n) i++;
		if (i >= n) break;
		if (a[i] > x) {
			ans++;
			i++;
		}
	}
	cout << ans;
}

