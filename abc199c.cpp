#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q;
	string s;
	cin >> n >> s >> q;
	string ans1 = s.substr(0, n);
	string ans2 = s.substr(n, n);
	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			a--;
			b--;
			if (a >= n) swap(ans2[a - n], ans2[b - n]);
			else {
				if (b >= n) swap(ans1[a], ans2[b - n]);
				else swap(ans1[a], ans1[b]);
			}
		}
		else swap(ans1, ans2);
	}
	cout << ans1 << ans2;
}

