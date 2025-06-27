#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	string s;
	int k;
	cin >> s >> k;
	int cnt = 0, ans = 0, n = s.size();
	for (int i = 0, j = 0;i < n;i++) {
		if (s[i] != 'X') cnt++;
		while (cnt > k) {
			if (s[j] != 'X') cnt--;
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
}

