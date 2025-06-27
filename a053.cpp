#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n >= 0 and n <= 10) cout << n * 6;
	if (n >= 11 and n <= 20) cout << 60 + (n - 10) * 2;
	if (n >= 21 and n <= 40) cout << 80 + (n - 20);
	else if (n >= 40) cout << 100;
}

