#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, sr = 0, sl = 0;
	cin >> n;
	int l[n], r[n];
	for (int i = 0;i < n;i++) {
		cin >> l[i] >> r[i];
		sr += r[i];
		sl += l[i];
	}
	if (sr < 0 or sl > 0) {
		cout << "No";
		return 0;
	}
	cout << "Yes" << '\n';
	for (int i = 0;i < n;i++) {
		cout << r[i] - min(r[i] - l[i], sr) << ' ';
		sr -= min(r[i] - l[i], sr);
	}
}
