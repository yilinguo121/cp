#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n), b(n);
	vector<int> x(n), y(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i] >> b[i];
		x[i] = a[i];
		y[i] = b[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	y.resize(unique(y.begin(), y.end()) - y.begin());
	for (int i = 0;i < n;i++) {
		cout << lower_bound(x.begin(), x.end(), a[i]) - x.begin() + 1;
		cout << ' ';
		cout << lower_bound(y.begin(), y.end(), b[i]) - y.begin() + 1;
		cout << '\n';
	}
}

