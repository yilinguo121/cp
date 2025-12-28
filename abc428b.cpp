#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	map<string, int> mp;
	vector<string> ans;
	int n, k;
	string s;
	cin >> n >> k >> s;
	int mx = 0;
	for (int i = 0;i + k <= n;i++) {
		string now = s.substr(i, k);
		mp[now]++;
		mx = max(mx, mp[now]);
	}
	cout << mx << '\n';
	for (auto [x, y] : mp) if (y == mx) ans.push_back(x);
	sort(ans.begin(), ans.end());
	for (auto x : ans) cout << x << ' ';
}

