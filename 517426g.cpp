#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1;i <= 200;i++) {
			if (i > n) break;
			for (int j = 1;j <= 200;j++) {
				if (i + j > n and i * j > n) break;
				for (int k = 1;k <= 200;k++) {
					if (i * j + k > n and i + j * k > n and i * j * k > n and i + j + k > n) break;
					if (i * j + k == n) ans++;
					if (i + j * k == n) ans++;
					if (i * j * k == n) ans++;
					if (i + j + k == n) ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}
