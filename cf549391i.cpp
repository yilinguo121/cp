#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int t = 1;
	for (int i = 1;i < n;i++) t = (t % 998244353) * 2 % 998244353;
	int sum = 0;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		a = a % 998244353;
		t = t % 998244353;
		sum = (sum + (t * a) % 998244353) % 998244353;
	}
	cout << sum;
}

