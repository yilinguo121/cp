#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	double ans = 0;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		double now = 1;
		for (int j = i;j >= 1;j--) now *= j;
		ans += now;
	}
	cout << ans;
}

