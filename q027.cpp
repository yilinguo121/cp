#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (!(n % 17)) cout << "Yes\n";
	else cout << min(n % 17, (n / 17 + 1) * 17 - n);
}

