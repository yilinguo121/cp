#include<bits/stdc++.h>
using namespace std;
int check (string s, string t) {
	int ans = 0;
	if (s[s.size() - 2] == t[0] and s[s.size() - 1] == t[1]) {
		return ans;
	}
	bool b = 0;
	for (int i = s.size() - 1;i >= 0;i--) {
		if (b == 0 and s[i] == t[1]) {
			b = 1;
		}else if (b == 1 and s[i] == t[0]) {
			return ans;
		}else {
			ans++;
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	int a = 0, b = 0, c = 0, d = 0;
	while (n--) {
		string s;
		cin >> s;
		a = check (s, "25");
		b = check (s, "50");
		c = check (s, "75");
		d = check (s, "00");
		int ans = 1e9;
		ans = min(ans, a);
		ans = min(ans, b);
		ans = min(ans, c);
		ans = min(ans, d);
		cout << ans << '\n';
	}
}
