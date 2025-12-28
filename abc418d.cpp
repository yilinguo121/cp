#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = n * (n - 1) / 2;
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		if (s[i] == '1') {
			if (cnt) ans -= max(1, cnt * (cnt - 1) / 2);
			cnt = 0;
		}
		else cnt++;
	}
	cout << ans;
}

