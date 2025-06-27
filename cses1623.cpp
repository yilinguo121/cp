#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	long long ans = 1e9;
	for (int i = 0;i < n;i++) cin >> v[i];
	for (int i = 0;i < (1 << n);i++) {
		long long sum1 = 0, sum2 = 0;
		for (int j = 0;j < n;j++) {
			if ((i >> j) & 1) sum1 += v[j];
			else sum2 += v[j];
		}
		ans = min(ans, abs(sum1 - sum2));
	}
	cout << ans;
}

