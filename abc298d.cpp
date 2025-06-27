#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const int MOD = 998244353;
signed main() {
	int t;
	cin >> t;
	queue<int> q;
	q.push(1);
	int size = 1, now = 1;
	vector<int> v(t + 2);
	v[0] = 1;
	for (int i = 1;i <= t + 1;i++) v[i] = (v[i - 1] * 10) % MOD;
	while (t--) {
		int t, x;
		cin >> t;
		if (t == 1) {
			cin >> x;
			q.push(x);
			now = (now * 10 + x) % MOD;
			size++;
		}
		if (t == 2) {
			int k = q.front();
			q.pop();
			now = (now - k * v[size - 1] % MOD + MOD) % MOD;
			size--;
		}
		if (t == 3) cout << now << '\n';
	}

}

