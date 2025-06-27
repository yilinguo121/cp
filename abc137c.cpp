#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0;i < n;i++) {
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
	}
	sort(s.begin(), s.end());
	int t = 1, ans = 0;
	for (int i = 1;i < n;i++) {
		if (s[i] == s[i - 1]) t++;
		else {
			ans = ans + (t * (t - 1) / 2);
			t = 1;
		}
	}
	ans = ans + (t * (t - 1) / 2);
	cout << ans << '\n';
}
