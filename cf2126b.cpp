#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int cnt = 0, ans = 0;
		bool flag = 0;
		while (n--) {
			int x;
			cin >> x;
			if (x or flag) {
				cnt = 0;
				flag = 0;
			}
			else {
				cnt++;
				if (cnt >= k) {
					ans++;
					flag = 1;
				}
			}
		}
		cout << ans << '\n';
	}
}

