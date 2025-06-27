#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	m = max(1, m);
	if (n % m) cout << n % m;
	else cout << "OK!";
}

