#include <bits/stdc++.h>
using namespace std;
#define int unsigned int
bool cmp (int a, int b) {
	if (__builtin_popcount(a) == __builtin_popcount(b)) return 0;
	return __builtin_popcount(a) < __builtin_popcount(b);
}
signed main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0;i < n;i++) cin >> v[i];
		stable_sort(v.begin(), v.end(), cmp);
		for (int i = 0;i < n;i++) cout << v[i] << ' ';
	}
}

