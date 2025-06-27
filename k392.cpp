#include <bits/stdc++.h>
using namespace std;
void f(float x) {
	if (x <= -10) cout << fixed << setprecision(1) << abs(x * x * x * x * x) - 33;
	else if (x > 10) cout << fixed << setprecision(1) << sqrt(x) * 2;
	else cout << fixed << setprecision(1) << x * -0.5 + 10;
}
int main() {
	float x;
	cin >> x;
	f(x);
}

