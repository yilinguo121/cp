#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main(){
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	while (n--){
		int l, r;
		cin >> l >> r;
		v.push_back({l, 1});
		v.push_back({r, -1});
	}
	sort(v.begin(), v.end());
	int now = 0, ans = 0;
	for (int i = 0;i < (int)v.size() - 1;i++){
		now += v[i].second;
		ans += now * now * (v[i + 1].first - v[i].first);
	}
	cout << ans;
}

