#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)) cout << "a leap year\n";
	else cout << "a normal year\n";
}

