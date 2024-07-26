#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 1, mod = 1e9 + 7;
	for (int i = 0;i < n;i++) {
		ans = ans * 2;
		ans = ans % mod;
	}
	cout << ans;

}
