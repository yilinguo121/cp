#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int sum = 0;
		for (int i = 0;i < n;i++) {
			int t;
			cin >> t;
			sum += t;
		}
		if ((float)sum / n > 59) cout << "no\n";
		else cout << "yes\n";
	}
}

