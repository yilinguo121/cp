#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v;
	int ans = 1e9;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		v.push_back(stoi(s, 0, 2));
		for (int j = 0;j < i;j++) {
			ans = min(ans, __builtin_popcount((v[i] ^ v[j])));
		}
	}
	cout << ans;
}
