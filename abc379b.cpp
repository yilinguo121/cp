#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	int ans = 0;
	int t = 0;
	for (int i = 0;i < n;i++) {
		if (s[i] == 'O') t++;
		if (s[i] == 'X') t = 0;
		if (t >= k) {
			ans++;
			t = 0;
		}
	}
	cout << ans;
}

