#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	map<char, int> mp, v;
	for (auto x : a) mp[x]++;
	for (auto x : b) v[x]++;
	int ans = 0, ans2 = 0;
	for (int i = '1';i <= '9';i++) ans += min(mp[i], v[i]);
	for (int i = 0;i < n;i++) if (a[i] == b[i]) ans2++;
	cout << ans2 << "A" << ans - ans2 << 'B';
}

