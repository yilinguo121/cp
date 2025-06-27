#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	long long ans = v[1] - v[0];
	for (int i = 2;i < n;i++) ans = gcd(ans, v[i] - v[i - 1]);
	cout << ans;
}

