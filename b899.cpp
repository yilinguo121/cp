#include <bits/stdc++.h>
using namespace std;
int main() {
	int x[3], y[3];
	for (int i = 0;i < 3;i++) cin >> x[i] >> y[i];
	int a = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
	int b = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
	int c = (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]);
	if (a > b and a > c) cout << x[0] + x[1] - x[2] << ' ' << y[0] + y[1] - y[2];
	else if (b > a and b > c) cout << x[0] + x[2] - x[1] << ' ' << y[0] + y[2] - y[1];
	else cout << x[1] + x[2] - x[0] << ' ' << y[1] + y[2] - y[0];
}

