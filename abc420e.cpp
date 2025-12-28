#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, q;
	cin >> n >> q;
	vector<int> pa(n + 1, -1);
	vector<vector<int>> sz(n + 1);
	vector<int> cnt(n + 1);
	vector<bool> flag(n + 1);
	for (int i = 1;i <= n;i++) {
		pa[i] = i;
		sz[i].push_back(i);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			int pa_a = pa[a];
			int pa_b = pa[b];
			if (pa[a] == pa[b]) continue;
			if (sz[pa[a]].size() < sz[pa[b]].size()) swap(pa_a, pa_b);
			for (auto x : sz[pa_b]) {
				pa[x] = pa_a;
				sz[pa_a].push_back(x);
			}
			cnt[pa_a] += cnt[pa_b];
			cnt[pa_b] = 0;
			sz[pa_b].clear();
			
		}
		if (t == 2) {
			int x;
			cin >> x;
			if (!flag[x]) cnt[pa[x]]++;
			else cnt[pa[x]]--;
			flag[x] = !flag[x];
		}
		if (t == 3) {
			int x;
			cin >> x;
			cout << (cnt[pa[x]] ? "Yes\n" : "No\n");
		}
	}
}
