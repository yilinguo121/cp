#include <bits/stdc++.h>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	int ans = 0;
	for (int i = m - 1;i < n;i++) {
		if (v[i] == v[i - 1] or v[i - 1] == v[i - 2] or v[i - 2] == v[i]) continue;
		ans++;
	}
	cout << ans;
}

