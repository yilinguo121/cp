#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	int ans = -10000000000, now = 0;
	for (int i = 0;i < n;i++) {
		now += v[i];
		ans = max(ans, now);
		if (now < 0){
			now = 0;
		}
	}
	cout << ans << '\n';
}
