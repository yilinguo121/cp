#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) cout << 1ll * a + b;
		if (t == 2) cout << 1ll * a - b;
		if (t == 3) cout << 1ll * a * b;
		if (t == 4) cout << 1ll * a / b;
		cout << '\n';
	}
}

