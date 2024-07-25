#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	n = n * 2;
	int a[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 2;i < n;i++) {
		if (a[i] == a[i - 2]) {
			ans++;
		}
	}
	cout << ans << '\n';
}
