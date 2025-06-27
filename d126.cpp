#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	while (cin >> n) {
		cout << (n / 4) * (n / 2 == n / 4 * 2 ? n / 4 : n / 4 + 1) << '\n';
	}
}

