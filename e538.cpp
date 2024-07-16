#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, d, r;
	while(cin >> n >> d >> r){
		if (n == 0 and d == 0 and r == 0){
			return 0;
		}
		vector<int> a(n), b(n);
		for (int i = 0;i < n;i++) {
			cin >> a[i];
		}
		for (int i = 0;i < n;i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		int ans = 0;
		for (int i = 0;i < n;i++) {
			a[i] += b[i];
			if (a[i] > d){
				ans += (a[i] - d) * r;
			}
		}
		cout << ans << '\n';
	}
}
