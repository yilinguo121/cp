#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(2 * n);
	for (int i = 0;i < 2 * n;i += 2) {
		cin >> v[i].f;
		v[i].s = 1;
		cin >> v[i + 1].f;
		v[i + 1].s = -1;
	}
	sort (v.begin(), v.end());
	int ans = 0, sum = 0;
	for (int i = 0;i < v.size();i++) {
		sum += v[i].s;
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}
