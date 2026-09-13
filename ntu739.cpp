#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> v;
int f(int l, int r) {
	if (l == r) return v[l];
	int m = (l + r) / 2, bl = -INF, br = -INF;
	for (int i = m, sum = 0;i >= l;i--) {
		sum += v[i];
		bl = max(bl, sum);
	}
	for (int i = m + 1, sum = 0;i <= r;i++) {
		sum += v[i];
		br = max(br, sum);
	}
	return max({f(l, m), f(m + 1, r), bl + br});
}
int main() {
	int n;
	cin >> n;
	v.resize(n);
	for (auto &x : v) cin >> x;
	cout << f(0, n - 1);
}
