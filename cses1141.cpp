#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n;
	cin >> n;
	map<int, int> mp;
	vector<int> v(n);
	int ans = 0;
	for (int i = 0, j = 0;i < n;i++) {
		cin >> v[i];
		mp[v[i]]++;
		while (mp[v[i]] > 1) {
			mp[v[j]]--;
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
}
