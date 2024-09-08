#include<bits/stdc++.h>
using namespace std;
int main() {
	int l, r;
	cin >> l >> r;
	if (l == 1 and r == 1) cout << "Invalid";
	else if (l == 1) cout << "Yes";
	else if (r == 1) cout << "No";
	else cout << "Invalid";
}
