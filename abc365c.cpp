#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m, e = 0;
	cin >> n >> m;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		sum += a[i];
		e = max(a[i], e);
	}
	if (sum <= m) {
		cout << "infinite";
		return 0;
	}
	int s = 0;
	while (1) {
		int sum = 0;
		int sum2 = 0;
		for (int i = 0;i < n;i++) {
			sum += min(s, a[i]);
		}
		if (sum <= m) {
			for (int i = 0;i < n;i++) {
				sum2 += min(a[i], s + 1);
			}
			if (sum2 <= m) {
				s = (e - s + 1) / 2 + s;
			}
			else break;
		}
		else {
			e = s - 1;
			s = 0;
		}
	}
	cout << s;

}
