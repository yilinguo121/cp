#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int a();
int f() {
	return 2 * a() - 3;
}
int g() {
	return 2 * a() + a() - 7;
}
int h() {
	return 3 * a() - 2 * a() + a();
}
int a() {
	string c;
	cin >> c;
	if (c == "f") return f() % mod;
	if (c == "g") return g() % mod;
	if (c == "h") return h() % mod;
	return stoi(c);
}
signed main() {
	int n;
	cin >> n;
	cout << (a() + mod) % mod;
}

