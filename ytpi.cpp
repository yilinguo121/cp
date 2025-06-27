#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, q;
	cin >> n >> q;
	int pos = 1;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) v[i] = i * 999;
	while (q--) {
		int p;
		cin >> p;
		if (p == pos) cout << 0;
		else {
			if ((v[p] - v[pos]) % 2) cout << 1;
			else cout << 0;
			v[p] = (v[p] + v[pos]) / 2;
			v[pos] = v[p];
		}
		for (int i = 1;i < n;i++) if (v[i] < v[pos]) pos = i;
	}
}

