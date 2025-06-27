#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	bitset<3001> st[3001];
	char v[n + 1][n + 1];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> v[i][j];
			if (i < j and v[i][j] == '1') st[i][j] = 1;
		}
	}
	long long ans = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			if (v[i][j] == '1') ans += (st[i] & st[j]).count();
		}
	}
	cout << ans;
}

