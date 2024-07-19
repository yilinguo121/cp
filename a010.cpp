#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << n;
		return 0;
	}
	for (int i = 2;i <= n;i++) {
		if (n % i == 0) {
			int t = 0;
			while (n % i == 0) {
				n = n / i;
				t++;
			}
			if (t == 1) {
				cout << i;
			}
			if (t > 1) {
				cout << i << '^' << t;
			}
			if (n > 1) {
				cout << " * ";
			}
		}
	}
}
