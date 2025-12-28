#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int ans = 0, n;
	cin >> n;
	for (int i = 1;i <= n;i++) ans += (i % 2 ? -1 : 1) * (i * i * i);
	cout << ans;
}

