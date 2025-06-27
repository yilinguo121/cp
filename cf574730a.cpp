#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> f(long long a, long long b) {
	if (b == 0) return {1, 0};
	else {
		pair<long long, long long> x = f(b, a % b);
		return {x.second, x.first - a / b * x.second};
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		pair<long long, long long> ans = f(a, b);
		cout << ans.first << ' ' << ans.second << '\n';
	}
}

