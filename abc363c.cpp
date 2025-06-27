#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	sort(s.begin(), s.end());
	int ans = 0;
	do {
		bool flag = 1;
		for (int i = 0;i < n - k + 1;i++) {
			int x = i, y = i + k - 1;
			bool is = 1;
			for (int m = 0;m < k / 2;m++, x++, y--) {
				if (s[x] != s[y]) is = 0;
				if (!is) break;
			}
			if (is) flag = 0;
			if (!flag) break;
		}
		if (flag) ans++;
	} while (next_permutation(s.begin(), s.end()));
	cout << ans << '\n';
}

