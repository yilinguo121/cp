#include<bits/stdc++.h>
using namespace std;
const int MAX = 500005;
vector<pair<int, int>> ls[MAX], rs[MAX];
int cnt[MAX] = {};
int a[MAX];
int ans[MAX] = {};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	cin >> q;
	for (int i = 1;i <= q;i++) {
		int l, r, x;
		cin >> l >> r >> x;
		ls[l].push_back({x, i});
		rs[r].push_back({x, i});
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < ls[i].size();j++) {
			ans[ls[i][j].second] -= cnt[ls[i][j].first];
		}
		cnt[a[i]]++;
		for (int j = 0;j < rs[i].size();j++) {
			ans[rs[i][j].second] += cnt[rs[i][j].first];
		}
	}
	for (int i = 1;i <= q;i++) {
		cout << ans[i] << '\n';
	}
}
