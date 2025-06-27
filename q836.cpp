#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int k, x1, y1, x2, y2;
	cin >> k >> x1 >> y1 >> x2 >> y2;
	int now = k;
	while (k > 0) {
		if (now % x1 == 0) k -= y1;
		if (now % x2 == 0) k -= y2;
		now += max(0, k);
	}
	cout << now;
}
