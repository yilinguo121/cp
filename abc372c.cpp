#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	int ans = 0;
	for (int i = 0;i < n - 2;i++) {
		if (s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C') ans++;
	}
	for (int i = 0;i < q;i++) {
		int x;
		char c;
		cin >> x >> c;
		x--;
		if (x < n - 2 and s[x] == 'A' and s[x + 1] == 'B' and s[x + 2] == 'C') ans--;
		if (x < n - 1 and x > 0 and s[x - 1] == 'A' and s[x] == 'B' and s[x + 1] == 'C') ans--;
		if (x > 1 and s[x - 2] == 'A' and s[x - 1] == 'B' and s[x] == 'C') ans--;
		s[x] = c;
		if (x < n - 2 and s[x] == 'A' and s[x + 1] == 'B' and s[x + 2] == 'C') ans++;
		if (x < n - 1 and x > 0 and s[x - 1] == 'A' and s[x] == 'B' and s[x + 1] == 'C') ans++;
		if (x > 1 and s[x - 2] == 'A' and s[x - 1] == 'B' and s[x] == 'C') ans++;
		cout << ans << '\n';
	}
}

