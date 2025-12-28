#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> v(n);
		int cnt = 0;
		bool ans = 1;
		for (auto x : s) {
			if (x == '1') {
				cnt++;
				if (cnt >= k) {
					ans = 0;
					break;
				}
			}
			else cnt = 0;
		}
		if (!ans) cout << "No\n";
		else {
			int now = n;
			for (int i = 0;i < n;i++) if (s[i] == '0') v[i] = now--;
			for (int i = 0;i < n;i++) if (s[i] == '1') v[i] = now--;
			cout << "Yes\n";
			for (auto x : v) cout << x << ' ';
			cout << '\n';
		}
	}
}

