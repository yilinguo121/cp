#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cnt[101] = {}, now = 0;
		bool ans = 1;
		while (n--) {
			int x;
			cin >> x;
			if (!x) ans = 0;
			else if (x > 0) {
				if (!cnt[x]++) now++;
			}
		}
		cout << (ans and now <= 1 ? "YES\n" : "NO\n");
	}
}

