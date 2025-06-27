#include<bits/stdc++.h>
using namespace std;
int main() {
	unsigned long long l, r;
	cin >> l >> r;
	unsigned long long x = l + r;
	unsigned long long y = r - l + 1;
	if (x % 2 == 0) x /= 2;
	else y /= 2;
	cout << x * y;
}
