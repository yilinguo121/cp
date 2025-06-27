#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1000000000000000000;
int mygcd (int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a == 0 or b == 0) return a + b;
	return __gcd(a, b);
} 
bool flag = 0;
int mylcm (int a, int b) {
	int x = a / mygcd(a, b);
	if (b > MAX / x) flag = 1;
	return x * b;
}
signed main() {
	int n;
	int ans;
	cin >> n;
	if (n == 1) {
		cin >> ans;
		if (ans > MAX) cout << "The answer is too large.";
		else cout << ans;
		return 0;
	}
	int t;
	cin >> ans >> t;
	ans = mylcm(ans, t);
	n -= 2;
	while(n--) {
		cin >> t;
		ans = mylcm(ans, t);
	}
	if (flag) {
		cout << "The answer is too large.";
		return 0;
	}
	cout << ans;
}
