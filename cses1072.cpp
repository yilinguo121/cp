#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	for (int k = 1;k <= n;k++) {
		cout << (k * k) * (k * k - 1) / 2 - (k - 1) * (k - 2) * 4 << '\n';
	}
}
