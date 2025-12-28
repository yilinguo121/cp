#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int cnt[26], n;
vector<string> ans;
string s;
void dfs(int id) {
	if (id == n) {
		ans.push_back(s);
		return;
	}
	for (int i = 0;i < 26;i++) {
		if (cnt[i]) {
			cnt[i]--;
			s[id] = i + 'a';
			dfs(id + 1);
			cnt[i]++;
		}
	}
}
int main() {
	cin >> s;
	n = s.size();
	for (auto x : s) cnt[x - 'a']++;
	dfs(0);
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x << '\n';
}
