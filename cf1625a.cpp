#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, l;
		cin >> n >> l;
		int a[l] = {};
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			for (int j = 0;j < l;j++) {
				if (((x >> j) & 1)) a[j]++;
			}
		}
		int ans = 0;
		for (int i = 0;i < l;i++) {
			if (a[i] > n - a[i]) {
				ans |= (1 << i);
			}
		}
		cout << ans << '\n';
		
	}
}

