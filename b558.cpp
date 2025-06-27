#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int ans = 1;
		for (int i = 1;i <= n;i++) ans += i - 1;
		cout << ans << '\n';
	}
}

