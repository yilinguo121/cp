#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long mod = 1000000007;
signed main(){
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v;
	while (k--){
		int a, l, r;
		cin >> a >> l >> r;
		v.push_back({l, a});
		v.push_back({r, -a});
	}
	sort(v.begin(), v.end());
	v.push_back({n + 1, 0});
	long long now = 0, q;
	cin >> q;
	long long ans = 0;
	while (q--){
		int s;
		cin >> s;
		for (int i = 0;i < (int)v.size() - 1;i++){
			now = now + v[i].second;
			if (now > s and v[i].first != v[i + 1].first){
				ans += now % mod * (v[i + 1].first - v[i].first + 1) % mod;
			}
		}
	}
	cout << ans % mod;
}
