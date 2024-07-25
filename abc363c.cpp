#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	sort(s.begin(), s.end());
	int ans = 0;
	int t = 0;
	bool f = 0;
	for (int i = k - 1, j = 0;i < n;i++, j++) {
		t = 0;
		for (int p = j, q = i, y = 0;y < k;y++, p++, q--) {
			if (s[p] == s[q]) {
				t++;
			}
		}
		if (t == k) {
			f = 1;
		}
	}
	if (!f) {
		ans++;
	}
	while (next_permutation(s.begin(), s.end())) {
		f = 0;
		for (int i = k - 1, j = 0;i < n;i++, j++) {
			t = 0;
			for (int p = j, q = i, y = 0;y < k;y++, p++, q--) {
				if (s[p] == s[q]) {
					t++;
				}
			}
			if (t == k) {
				f = 1;
			}
		}
		if (!f) {
			ans++;
		}
	}
	cout << ans << '\n';
}
