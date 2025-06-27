#include <bits/stdc++.h>
using namespace std;
int main() {
	long long a, b;
	cin >> a >> b;
	long long ans = 1;
	for (int i = 0;i < b;i++) ans *= a;
	cout << a << '^' << b << " = " << ans;
}

