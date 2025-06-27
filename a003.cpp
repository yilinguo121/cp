#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, d;
	cin >> m >> d;
	int s = (2 * m + d) % 3;
	if (!s) cout << "普通";
	else if (s == 1) cout << "吉";
	else cout << "大吉";
}
