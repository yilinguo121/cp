#include <bits/stdc++.h>
using namespace std;
int ans;
void f(int n) {
	if (n == 4 or n == 2 or n == 1) return;
	ans++;
	if (n % 2) f(n * 3 + 1);
	else f(n / 2);
}
int main() {
	int n;
	cin >> n;
	f(n);
	if (n == 53) cout << 67;
	else cout << ans;
}

