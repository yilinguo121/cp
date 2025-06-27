#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	string s, x;
	cin >> s >> x;
	int n;
	cin >> n;
	while (n--) {
		char a, b;
		cin >> a >> b;
		for (auto &c : s) if (c == a) c = b;
	}
	int ans = 0;
	for (int i = 0;i < s.size();i++) if (s[i] != x[i]) ans++;
	cout << ans;
}

