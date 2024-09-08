#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, x, y;
	cin >> n >> x >> y;
	int suma = 0, sumb = 0;
	vector<int> a(n), b(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = n - 1, cnt = 1;i >= 0;i--, cnt++) {
		suma += a[i];
		sumb += b[i];
		if (suma > x or sumb > y) {
			cout << cnt;
			return 0;
		}
	}
	cout << n;
}
