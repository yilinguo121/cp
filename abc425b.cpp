#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> cnt;
	for (auto &x : v) cin >> x, cnt[x]++;
	for (auto [x, y] : cnt) if (x != -1 and y >= 2) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	for (int i = 0, j = 1;i < n;i++) {
		while (cnt[j]) j++;
		if (v[i] == -1) {
			cout << j << ' ';
			j++;
		}
		else cout << v[i] << ' ';
	}
}

