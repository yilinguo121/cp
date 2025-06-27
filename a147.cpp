#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 1;i < n;i++) {
			if (i % 7 == 0) continue;
			cout << i << ' ';
		}
		cout << '\n';
	}
}

