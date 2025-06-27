#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
	long long a, b;
	cin >> a >> b;
	cout << ((a % mod) * (b % mod)) % mod;

}

