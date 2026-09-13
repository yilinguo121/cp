#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO;
	int n;
	cin >> n;
	vector<int> a(n + 2);
	for (int i = 0;i < n;i++) {
		int l, r;
		cin >> l >> r;
		a[l]++, a[r + 1]--;
	}
	for (int i = 1;i <= n;i++) a[i] += a[i - 1];
	string ans;
	for (int i = 0;i <= n;i++) ans += (a[i] == i ? "1" : "0");
	cout << ans;
}
