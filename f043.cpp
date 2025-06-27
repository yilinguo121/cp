#include <bits/stdc++.h>
using namespace std;
int main() {
	long long a, b, c;
	cin >> c >> a;
	if (c == a) a -= 3;
	b = c - a;
	if (b < a) swap(a, b);
	cout << a << '+' << b << '=' << c;
}

