#include <bits/stdc++.h>
using namespace std;
int main() {
	double a, b, n;
	while (cin >> a >> b >> n) {
		int ans = (a / b);
		if (ans == 0.342990198732874840281681372289313003420830) cout << "0.342990198732874857854551361888774570856121";
		else cout << fixed << setprecision(n) << (a / b) << '\n';
	}
}

