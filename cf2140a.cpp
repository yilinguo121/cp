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
		int cnt = 0;
		for (auto x : s) if (x == '0') cnt++;
		int ans = 0;
		for (int i = 0;i < cnt;i++) if (s[i] == '1') ans++;
		cout << ans << '\n';
	}
}

