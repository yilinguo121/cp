#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int n, m;
string s[15];
vector<pair<int, pair<int, int>>> p;
unordered_set<string> st;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
pair<int, int> apple;
string f(vector<pair<int, int>> body) {
	string ss;
	for (auto [x, y] : body) {
		ss += 'a' + x;
		ss += 'a' + y;
	}
	return ss;
}
void bfs (vector<pair<int, int>> body) {
	queue<pair<vector<pair<int, int>>, int>> q; //前存座標 後存路徑長
	q.push({body, 0});
	st.insert(f(body));
	while (!q.empty()) {
		auto [now, cnt] = q.front();
		q.pop();
		if (now[0] == apple) {
			cout << cnt;
			return;
		}
		for (int i = 0;i < 4;i++) {
			int nx = now[0].first + dx[i];
			int ny = now[0].second + dy[i];
			if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
			if (s[nx][ny] == '#') continue;
			bool flag = 0;
			for (int j = 0;j < now.size() - 1;j++) {
				if (now[j] == make_pair(nx, ny)) flag = 1;
			}
			if (flag) continue;
			vector<pair<int, int>> next(now.size());
			next[0] = {nx, ny};
			for (int j = 1;j < now.size();j++) next[j] = now[j - 1];
			if (st.insert(f(next)).second) q.push({next, cnt + 1});
		}
	}
	cout << -1;
	return;
}
int main() {
	IO
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> s[i];
		for (int j = 0;j < m;j++) {
			if (s[i][j] >= '1' and s[i][j] <= '9') p.push_back({s[i][j] - '0', {i, j}});
			if (s[i][j] == '@') apple = {i, j};
		}
	}
	sort(p.begin(), p.end());
	vector<pair<int, int>> body;
	for (int i = 0;i < p.size();i++) body.push_back(p[i].second);
	bfs(body);
}

