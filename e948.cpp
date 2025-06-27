#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		bool g;
		float a, h, w;
		cin >> g >> a >> h >> w;
		if (g) {
			cout << fixed << setprecision(2) << 13.7 * w + 5.0 * h - 6.8 * a + 66;
		}
		else {
			cout << fixed << setprecision(2) << 9.6 * w + 1.8 * h - 4.7 * a + 655;
		}
		cout << '\n';
	}
}

