#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	int h = 0, ans = 0;
	while (1) {
		int sum = 0;
		for (int i = 0;i < n and sum <= x;i++) sum += max(0, h - a[i]);
		if (sum > x) break;
		ans = h++;
	}
	cout << ans;
}

