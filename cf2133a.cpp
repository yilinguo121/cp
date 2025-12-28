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
		int cnt[101] = {};
		bool ans = 0;
		while (n--) {
			int x;
			cin >> x;
			if (cnt[x]++) ans = 1;
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}

