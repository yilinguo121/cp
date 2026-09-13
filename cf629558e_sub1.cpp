#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	while (q--)	{
		int l, r;
		cin >> l >> r;
		cout << v[l - 1] << '\n';
	}
}
