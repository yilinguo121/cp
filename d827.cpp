#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 0;
	ans += n / 12 * 50;
	n %= 12;
	ans += n * 5;
	cout << ans;
}

