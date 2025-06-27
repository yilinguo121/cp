#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, int>>> v(n + 1);
		while (m--) {
			int a, b;
			string s;
			cin >> a >> b >> s;
			int c = (s == "imposter");
			v[a].push_back({b, c});
			v[b].push_back({a, c});
		}
		vector<int> a(n + 1, -1);
		int ans = 0;
		bool flag = 1;
		for (int i = 1;i <= n;i++) {
			if (a[i] != -1) continue;
			queue<int> q;
			int cnt[2] = {};
			q.push(i);
			a[i] = 0;
			cnt[0]++;
			while (!q.empty() and flag) {
				int x = q.front();
				q.pop();
				for (auto [y, c] : v[x]) {
					int k = a[x] ^ c; 
					// 如果他說對面是殺手，那他們一定是不同陣營 (如果他說謊就是a殺手 b平名，如果沒有的話就是b殺手 a平名)
					// 如果他說對面是平名，那他們一定同陣營 (如果他說謊，就兩個都是殺手，如果每有就是兩個都平名)
					if (a[y] == -1) {
						q.push(y);
						a[y] = k;
						cnt[k]++;
					}
					if (a[y] != k) {
						flag = 0;
						break;
					}
				}
			}
			if (!flag) break;
			ans += max(cnt[0], cnt[1]);
		}
		cout << (flag ? ans : -1) << '\n';
	}
}
