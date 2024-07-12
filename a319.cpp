#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	int ans = 0;
	int t = v[0];
	for (int i = 1;i < n;i++) {
		ans = max(ans, v[i] - t);
		t = min(t, v[i]);
	}
	cout << ans << '\n';
}
