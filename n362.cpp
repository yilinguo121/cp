#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int n) {
	for (int i = 2;i * i <= n;i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
signed main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 2;i * i <= n;i++) {
		if (n % i == 0) {
			int a = i;
			int b = n / i;
			if (check(a) and check(b)) {
				cout << a << ' ' << b;
				return 0;
			}
		}
	}
	cout << 0 << ' ' << 0;
}
