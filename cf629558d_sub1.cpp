#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int mx = 1;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		mx *= a[i];
	}
	for (int k = 1;k <= mx;k++) {
		int cnt = 0;
		for (int i = 0;i < n;i++) if (k % a[i] == 0) cnt++;
		if (cnt == n) {
			cout << k;
			return 0;
		}
	}
}
