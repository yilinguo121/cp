#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
		if (i > 0) v[i] += v[i - 1];
	}
	unsigned long long x;
	cin >> x;
	long long ans = x / v[n - 1] * n;
	x %= v[n - 1];
	ans += upper_bound(v.begin(), v.end(), x) - v.begin() + 1;
	cout << ans;
}

