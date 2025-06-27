#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0;i < n;i++) {
		int l = i + 1, r = i + 1;
		for (int j = i + 1;j < n;j++) {
			while (l < n and v[i] * v[i] + v[j] * v[j] >= v[l] * v[l]) l++; // l的位置是第一個成立頓三角形的k
			while (r < n and v[i] + v[j] > v[r]) r++; // r是第一個構不成三角形的k
			ans += r - l; // 所以 k ∈ [l, r)
		}
	}
	cout << ans;
}
