#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	int a = -n;
	//y = sum + ax
	int ans = sum + a * v[0];
	for (int i = 1;i < n;i++) {
		a += 2;
		sum -= v[i - 1] * 2;
		ans = min(ans, sum + a * v[i]);
	}
	cout << ans;
}
