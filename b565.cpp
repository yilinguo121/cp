#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int ans = 0;
		int sum = 0;
		for (int i = 0;i < n;i++) {
			int t;
			cin >> t;
			sum += t;
			ans = max(sum, ans);
			sum = max(sum, 0);
		}
		cout << ans << '\n';
	}
}


