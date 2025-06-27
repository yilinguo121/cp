#include<bits/stdc++.h>
using namespace std;
const long long a = 998244353;
int main() {
	long long n;
	cin >> n;
	n = n % a;
	if (n < 0) n += a;
	cout << n;
}
