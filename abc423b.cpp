#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int l = -1, r = -1;
	for (int i = 0;i < n;i++) if (v[i]) {
		l = i;
		break;
	}
	for (int i = n - 1;i >= 0;i--) if (v[i]) {
		r = i;
		break;
	}
	cout << max(0, r - l);
}
