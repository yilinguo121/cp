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
	reverse(b.begin(), b.end());
	int l = 0, r = n - 1;
	for (int i = 0;i < n;i++) {
		if (a[i] != b[i]) continue;
		if (a[l] != b[i] and b[l] != a[i]) swap(b[l++], b[i]);
		else if (a[r] != b[i] and b[r] != a[i]) swap(b[r--], b[i]);
		else {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes\n";
	for (auto x : b) cout << x << ' ';
}
