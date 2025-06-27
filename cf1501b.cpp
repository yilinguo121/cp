#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> m;
	while (m--) {
		cin >> n;
		int a[n + 1] = {};
		for (int i = 0;i < n;i++) {
			int t;
			cin >> t;
			a[i + 1]--;
			a[max(i - t + 1, 0)]++;
		}
		if (a[0]) cout << 1 << ' ';
		else cout << 0 << ' ';
		for (int i = 1;i < n;i++) {
			a[i] += a[i - 1];
			if (a[i] > 0) cout << 1 << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
}
