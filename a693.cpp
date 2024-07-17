#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		int a[100005];
		for (int i = 1;i <= n;i++) {
			cin >> a[i];
			a[i] += a[i - 1];
		}
		for (int i = 0;i < m;i++) {
			int t, b;
			cin >> t >> b;
			cout << a[b] - a[t - 1] << '\n';
		}
	}
}
