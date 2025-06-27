#include <bits/stdc++.h>
using namespace std;
int f(int t) {
	if (t == 1 or t == 3) return 1;
	else if (t <= 0) return 0;
	else return f(t - 5) + f(t - 3);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	cout << f(t);
}

