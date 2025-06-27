#include <bits/stdc++.h>
using namespace std;
int main() {
	double c;
	cin >> c;
	double l = 0, r = 1e5;
	for (int i = 0;i < 60;i++) {
		double m = (l + r) / 2;
		if (m * m + sqrt(m) > c) r = m;
		else l = m;
	}
	cout << fixed << setprecision(15) << (l + r) / 2;
}

