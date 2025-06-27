#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int l;
	cin >> l;
	l--;
	int ans = 1;
	for (int i = 0;i < 11;i++) {
		ans = ans * (l - i) / (i + 1);
	}
	cout << ans;
}
