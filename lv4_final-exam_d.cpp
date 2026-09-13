#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int ans = 0;
	for (int i = 0;i < n;i++) for (int j = i + 1;j < n;j++) for (int k = j + 1;k < n;k++) if (v[i] > v[k] and v[k] > v[j]) ans++;
	cout << ans;
}
