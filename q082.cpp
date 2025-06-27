#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n, a, b;
	cin >> n >> a >> b;
	if (n % 2) {
		cout << "能\n";
		cout << (pow(a, n) + pow(b, n));
	}
	else cout << "不能";
}

