#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n, k;
	cin >> n >> k;
	int a = 0, b = -1;
	map<int, int> mp;
	int st = 0;
	vector<int> v(n);
	for (int i = 0, j = 0;i < n;i++) {
		cin >> v[i];
		if (!mp[v[i]]) st++;
		mp[v[i]]++;
		while (j < i and st > k) {
			mp[v[j]]--;
			if (!mp[v[j]]) {
				st--;
			}
			j++;
		}
		if (i - j > b - a) {
			b = i;
			a = j;
		}
	}
	cout << a + 1 << ' ' << b + 1;
}

