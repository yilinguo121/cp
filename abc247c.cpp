#include <bits/stdc++.h>
using namespace std;
void f(int n) {
	if (n == 1) {
		cout << 1;
		return;
	}
	f(n - 1);
	cout << ' ';
	cout << n;
	cout << ' ';
	f(n - 1);
}
int main() {
	int n;
	cin >> n;
	f(n);
}

