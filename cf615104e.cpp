#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (auto &x : s) cin >> x;
	int cnt[26] = {};
	map<pair<int, int>, int> mp;
	vector<vector<int>> v(26);
	for (int i = 1;i < n;i++) {
		bool flag = 1;
		for (int j = 0;j < min(1 * s[i - 1].size(), 1 * s[i].size());j++) {
			if (s[i - 1][j] != s[i][j]) {
				if (!mp[{s[i - 1][j] - 'a', s[i][j] - 'a'}]) {
					v[s[i - 1][j] - 'a'].push_back(s[i][j] - 'a');
					cnt[s[i][j] - 'a']++;
				}
				mp[{s[i - 1][j] - 'a', s[i][j] - 'a'}]++;
				flag = 0;
				break;
			}
		}
		if (flag and s[i - 1].size() > s[i].size()) {
			cout << "Impossible";
			return 0;
		}
	}
	queue<int> q;
	string ans;
	for (int i = 0;i < 26;i++) {
		if (!cnt[i]) q.push(i);
	}
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		ans += (char)(x + 'a');
		for (auto nx : v[x]) {
			if (!--cnt[nx]) {
				q.push(nx);
			}
		}
	}
	if (ans.size() != 26) cout << "Impossible";
	else cout << ans;
}

