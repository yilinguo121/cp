#include <bits/stdc++.h>
using namespace std;
int f(int n) {
	if (n == 0) return 0;
	return n / 5 + f(n / 5);
}
int main() {
	int n;
	cin >> n;
	cout << f(n);
}

