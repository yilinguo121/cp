#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	string s;
	while (cin >> s) {
		int ans = INF;
		for (int i = 0;i < (1 << s.size());i++) {
			string n = s;
			for (int j = 0;j < s.size();j++) {
				if (!(n[j] % 2)) {
					if (i & (1 << j)) n[j]++;
					else {
						if (n[j] == '0') n[j] = '9';
						else n[j]--;
					}
				}
			}
			ans = min(ans, 1ll * abs(stoi(s) - stoi(n)));
		}
		cout << ans << '\n';
	}
}

