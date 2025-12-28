#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> now, ans;
int n, sum;
void dfs(int t) {
	if (t > n) {
		sum++;
		ans = max(ans, now);
		return;
	}
	for (int i = 1;i < now.size();i++) {
		if (!(t % (now[i - 1] + now[i]))) {
			now.insert(now.begin() + i, t);
			dfs(t + 1);
			now.erase(now.begin() + i);
		}
	}
}
int main() {
	IO
	cin >> n;
	if (n == 1) {
		cout << "1\n0 1";
		return 0;
	}
	now = {0, 1};
	dfs(2);
	cout << sum << '\n';
	for (auto x : ans) cout << x << ' ';
}
