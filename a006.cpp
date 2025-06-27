#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b * b - 4 * a * c < 0) {
		cout << "No real root";
		return 0;
	}
	int d = (-b + sqrt(b * b - 4 * a * c))/ (2 * a);
	int e = (-b - sqrt(b * b - 4 * a * c))/ (2 * a);
	if (e > d) swap(e, d);
	if (e == d) cout << "Two same roots x=" << d;
	else cout << "Two different roots x1=" << d << " , x2=" << e;
}
