#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (1) {
		int t;
		cin >> t;
		if (!t) return 0;
		if (t % n) cout << n - t % n << '\n';
		else cout << t / n << '\n';
	}
}
