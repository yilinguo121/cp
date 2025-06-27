#include <bits/stdc++.h>
using namespace std;
long long ans[2000001] = {};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1;i <= 2000000;i++) {
		int t = i;
		while (t <= 2000000) {
			ans[t]++;
			t += i;
		}
	}
	while (n--) {
		int x;
		cin >> x;
		cout << ans[x] << '\n';
	}
}

