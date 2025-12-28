#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int cnt = 0, MAX = 0, sum = 0;
		for (auto x : s) {
			if (x == '1') cnt++;
			else {
				MAX = max(MAX, cnt);
				sum += cnt;
				cnt = 0;
			}
		}
		sum += cnt;
		cout << (2 * k > n or sum <= k ? "Alice\n" : "Bob\n");
	}
}

