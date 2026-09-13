#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int unsigned long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1, j = 0;j <= 63;i *= 2, j++) v.push_back(i);
	while (n--) {
		long long a;
		cin >> a;
		cout << lower_bound(v.begin(), v.end(), a) - v.begin() << '\n';
	}
}

