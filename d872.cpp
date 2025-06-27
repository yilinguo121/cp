#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n){
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int ans = 0;
		while (n > 3) {
			int c = a[1] + a[0] + a[n - 1] + a[1];
			int b = a[n - 1] + a[0] + a[n - 2] + a[0];
			int sum = min(c, b);
			ans += sum;
			n -= 2;
		}
		if (n == 3){
			ans += a[0] + a[1] + a[2];
		}
		else if (n == 2){
			ans += a[1];
		}
		else if (n == 1){
			ans += a[0];
		}
		cout << ans << '\n';
	}
}
