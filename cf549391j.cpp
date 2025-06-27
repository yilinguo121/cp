#include <bits/stdc++.h>
using namespace std;
int c[1048576] = {};
int main() {
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0;i < n;i++) cin >> b[i];
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		c[t]++;
	}
	long long ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			ans += c[(a[i] ^ b[j])];
		}
	}
	cout << ans;
}

