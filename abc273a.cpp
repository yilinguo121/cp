#include <bits/stdc++.h>
using namespace std;
int f(int n) {
	if (!n) return 1;
	return f(n - 1) * n;
}
int main() {
	int n;
	cin >> n;
	cout << f(n);
}

