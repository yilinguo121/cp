#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	vector<int> v(10);
	int n, ans = 0;
	for (auto &x : v) cin >> x;
	cin >> n;
	for (auto x : v) if (x - n - 30 <= 0) ans++;
	cout << ans;
}

