#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		queue<int> q;
		vector<bool> vis(1 << n);
		q.push(0);
		vis[0] = 1;
		bool ans = 0;
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			if (t == (1 << n) - 1) {
				ans = 1;
				break;
			}
			for (int i = 0;i < n;i++) {
				if ((t & (1 << i)) == 0) {
					int nt = t | (1 << i);
					if (s[nt - 1] != '1' and !vis[nt]) {
						q.push(nt);
						vis[nt] = 1;
					}
				}
			}
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
}
