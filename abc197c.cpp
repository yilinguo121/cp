#include <bits/stdc++.h>
using namespace std;
vector<int> v(20);
int ans = 2147483647;
int n;
void f(int i, int o, int x) {
	if (i == n) {
		ans = min(ans, o ^ x);
		return;
	}
	f(i + 1, (o | v[i]), x);
	f(i + 1, v[i], (o ^ x));
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) cin >> v[i];
	f(1, v[0], 0);
	cout << ans;
}

