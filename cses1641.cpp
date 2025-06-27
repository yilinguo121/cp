#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			if (v[i].first + v[l].first + v[r].first == x) {
				cout << v[i].second << ' ' << v[l].second << ' ' << v[r].second << '\n';
				return 0;
			}
			else if (v[i].first + v[l].first + v[r].first > x) r--;
			else l++;
		}
	}
	cout << "IMPOSSIBLE\n";
}

