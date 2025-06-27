#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = n - i;j > 0;j--) cout << "_";
		for (int j = 1;j <= i;j++) cout << "*";
		cout << '\n';
	}
}

