#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main() {
	int n, m, c;
	cin >> n >> m >> c;
	vector<vector<int>> v(n + 5, vector<int>(m + 5));
	vector<pair<int, int>> p(c + 5);
	vector<int> vis(c + 1);
	for (int i = 1;i <= c;i++) {
		cin >> p[i].x >> p[i].y;
		v[p[i].x][p[i].y] = i;
	}
	int ans = 0;
	for (int i = 1;i <= c;i++) {
		if (vis[i]) continue;
		ans++;
		vis[i] = 1;
		queue<int> q;
		q.push(i);
		while(q.size()) {
			int t = q.front();
			q.pop();
			for (int j = max(1, p[t].x - 2);j <= min(n, p[t].x + 2);j++) {
				for (int k = max(1, p[t].y - 2);k <= min(m, p[t].y + 2);k++) {
					if (!vis[v[j][k]] and v[j][k]) {
						q.push(v[j][k]);
						vis[v[j][k]] = 1;
					}
				}
			}
		}
	}
	cout << ans;
}
