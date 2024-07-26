#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 1;i <= n;i++) {
		int t;
		if (i < n) {
			cin >> t;
			a += t;
		}
		b += i;
	}
	cout << b - a;
}
