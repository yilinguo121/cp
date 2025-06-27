#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = 0;i < n;i++) {
			if (b[i] == '1' and a[i] == '0') {
				ans++;
				a[i] = '2';
			}
			else if (b[i] == '1' and a[i - 1] == '1') {
				ans++;
				a[i - 1] = '2';
			}
			else if (b[i] == '1' and a[i + 1] == '1') {
				ans++;
				a[i + 1] = '2';
			}
		}
		cout << ans << '\n';
	}
}

