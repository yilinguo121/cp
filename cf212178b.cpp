#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000005;
int a[N];
signed main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int off, on;
		cin >> off >> on;
		a[off]++;
		a[on]--;
	}
	for (int i = 1;i < N;i++) a[i] += a[i - 1];
	int ans = 0;
	for (int i = 1;i < N;i++) ans += a[i] * a[i];
	cout << ans;
}
