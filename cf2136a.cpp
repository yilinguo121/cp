#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << (((min(a, b) + 1) * 2 >= max(a, b)) and (min(c - a, d - b) + 1) * 2 >= max(c - a, d - b) ? "Yes\n" : "No\n");
	}
}
