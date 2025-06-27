#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	unsigned long long ans = 0;
	cin >> n;
	unsigned long long t = 1;
	for (int i = 1;i <= n;i++) {
		t *= i;
		ans += t;
	}
	cout << ans;
}

