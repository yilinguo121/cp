#include <bits/stdc++.h>
using namespace std;
int main() {
	long long a, b;
	cin >> a >> b;
	if (b > a) swap(a, b);
	long long ans = 0;
	while (b) {
		long long t = a / b;
		ans += t;
		a -= b * t;
		swap(a, b);
	}
	cout << ans;
}

