#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100000;
vector<int> v(N + 1);
vector<int> a(2 * N + 5, -1);
signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	a[n] = 0;
	for (int i = 1;i <= n;i++) {
		if (s[i - 1] == '1') v[i] = 1;
		else v[i] = -1;
		v[i] += v[i - 1];
		if (a[v[i] + n] == -1) a[v[i] + n] = i;
		else ans = max(ans, i - a[v[i] + n]);
	}
	cout << ans << '\n';
}
