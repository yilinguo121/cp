#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		x--;
		string s;
		cin >> s;
		if (x == 0 or x == n - 1) {
			cout << "1\n";
			continue;
		}
		int l = 0, r = 0;
		for (int i = 0;i < x;i++) {
			if (s[i] == '#') l++;
		}
		for (int i = x + 1;i < n;i++) {
			if (s[i] == '#') r++;
		}
		cout << ((l or r) ? min(l, r) + 2 : 1) << '\n';
	}
}

