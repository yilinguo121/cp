#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> pos;
	for (int i = 0;i < 2 * n;i++) {
		if (s[i] == 'A') pos.push_back(i);
	}
	int now = 0, ans1 = 0, ans2 = 0;
	for (auto x : pos) {
		ans1 += abs(now - x);
		now += 2;
	}
	now = 1;
	for (auto x : pos) {
		ans2 += abs(now - x);
		now += 2;
	}
	cout << min(ans1, ans2);
}

