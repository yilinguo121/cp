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
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		int l = 0, r = n - 1;
		cout << (v[l] > v[r] ? "LR" : "RL");
		l++, r--;
		int i = 1;
		while (l < r) {
			if (i % 2) {
				cout << (v[l] < v[r] ? "LR" : "RL");
				l++, r--;
			}
			else {
				cout << (v[l] > v[r] ? "LR" : "RL");
				l++, r--;
			}
			i++;
		}
		if (l == r) cout << "L";
		cout << '\n';
	}
}

