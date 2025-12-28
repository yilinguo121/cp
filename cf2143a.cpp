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
		vector<int> v(n), pos(n + 1);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
		}
		bool ans = 1;
		int l = 0, r = n - 1;
		for (int i = 1;i <= n;i++) {
			if (v[l] == i) l++;
			else if (v[r] == i) r--;
			else {
				ans = 0;
				break;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}

