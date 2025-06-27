#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
int a[N] = {};
signed main() {
	int n, w;
	cin >> n >> w;
	for (int i = 0;i < n;i++) {
		int s, t, p;
		cin >> s >> t >> p;
		a[s] += p;
		a[t] -= p;
	}
	for (int i = 0;i < N;i++) {
		if (i > 0) a[i] += a[i - 1];
		if (a[i] > w) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}
