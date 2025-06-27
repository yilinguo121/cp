#include <bits/stdc++.h>
using namespace std;
bitset<40000001> v = {};
int main() {
	int a, d, n;
	cin >> a >> d >> n;
	v[1] = 1;
	for (int i = 2;i < 40000001;i++) {
		if (!v[i]) {
			for (int j = i + i;j < 40000001;j += i) {
				v[j] = 1;
			}
		}
	}
	int ans = n;
	for (int i = 0;i < n;i++) {
		ans -= v[a];
		a += d;
	}
	cout << ans;
}

