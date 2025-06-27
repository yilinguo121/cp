#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int n;
	cin >> n;
	long long int ans = 1;
	while (n > 0) {
		int x = n % 10;
		n /= 10;
		if (n == 0) x--;
		ans *= (x + 1);
	}
	cout << ans;
}
