#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	long long ans = 0;
	for (int i = 0, j = 0;i < n;i++) {
		while (j + 1 < n and v[i] * 2 > v[j + 1]) j++;
		ans += n - 1 - j;
	}
	cout << ans;
}

