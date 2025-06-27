#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--) {
		int a, b, c;
		cin >> a >> b >> c;
		int t = b * b - 4 * a * c;
		if (t >= 0 and (int)sqrt(t) * (int)sqrt(t) == t) cout << "Yes\n";
		else cout << "No\n";
	}
}

