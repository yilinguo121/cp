#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	string s[n];
	int cnt[m] = {};
	for (auto &x : s) {
		cin >> x;
		for (int i = 0;i < m;i++) cnt[i] += (x[i] == '1');
	}
	vector<int> ans;
	int now = 0;
	int score[n] = {};
	for (int i = 0;i < m;i++) {
		if (!cnt[i] or cnt[i] == n) {
			for (auto &x : score) x++;
		}
		else if (cnt[i] > n / 2) {
			for (int j = 0;j < n;j++) if (s[j][i] == '0') score[j]++;
		}
		else {
			for (int j = 0;j < n;j++) if (s[j][i] == '1') score[j]++;
		}
	}
	for (int i = 0;i < n;i++) now = max(now, score[i]);
	for (int i = 0;i < n;i++) if (now == score[i]) cout << i + 1 << ' ';
}
