#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
set<char> st;
string s[3];
int mp[26];
vector<char> v;
bool vis[10];
bool check() {
	string t[3];
	for (int i = 0;i < 3;i++) {
		t[i] = s[i];
		bool flag = 1;
		for (auto &x : t[i]) {
			if (flag and !mp[x - 'a']) return 0;
			if (mp[x - 'a']) flag = 0;
			x = mp[x - 'a'] + '0';
		}
	}
	return stoll(t[0]) + stoll(t[1]) == stoll(t[2]);
}
void dfs(int id) {
	if (id == st.size()) {
		if (check()) {
			for (auto x : s) {
				for (auto y : x) cout << mp[y - 'a'];
				cout << '\n';
			}
			exit(0);
		}
		return;
	}
	for (int i = 0;i <= 9;i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		mp[v[id] - 'a'] = i;
		dfs(id + 1);
		vis[i] = 0;
		mp[v[id] - 'a'] = -1;
	}
}
int main() {
	cin >> s[0] >> s[1] >> s[2];
	for (auto x : s) st.insert(x.begin(), x.end());
	if (st.size() > 10) {
		cout << "UNSOLVABLE";
		return 0;
	}
	for (auto x : st) v.push_back(x);
	memset(mp, -1, sizeof(mp));
	dfs(0);
	cout << "UNSOLVABLE";
}

