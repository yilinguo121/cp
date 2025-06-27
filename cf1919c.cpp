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
		int a = INF, b = INF, ans = 0;
		while (n--) {
			int x;
			cin >> x;
			if (a > b) swap(a, b);
			if (x <= a) a = x;
			else if (x <= b) b = x;
			else {
				ans++;
				a = x;
			}
		}
		cout << ans << '\n';
	}
}

