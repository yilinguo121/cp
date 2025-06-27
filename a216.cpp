#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int n) {
	if (n == 1) return 1;
	return n + f(n - 1);
}
int g(int n) {
	if (n == 1) return 1;
	return f(n) + g(n - 1);
}
signed main() {
	int n;
	while (cin >> n) {
		cout << f(n) << ' ' << g(n) << '\n';
	}
}
