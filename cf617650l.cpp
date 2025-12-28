#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
/***************************************************************
如果選k個數字

那麼如果選最小的k個數
子集s = {1, 3, 5,..., 2k - 1}
=> 所以總和是[(2k - 1) + 1] * k / 2
=> (2k^2) / 2
=> k^2

如果選的是最大的k個數
子集s = {2y - (2k - 1),..., 2y - 1}
=> 所以總和是{[2y - (2k - 1)] + [2y - 1]} * k / 2
=> (4y - 2k) * k / 2
=> k(2y - k)

然後如果x是奇數就要選奇數個奇數相加，否則就選偶數個奇數相加

所以我們要找到最小的k滿足
k^2 <= x <= k(2y - k) and x % 2 = k % 2
***************************************************************/
signed main() {
	IO
	int x, y;
	cin >> x >> y;
	if (!x) {
		cout << 0;
		return 0;
	}
	for (int k = 1;k * k <= x;k++) {
		if (k * k <= x and x <= k * (2 * y - k) and x % 2 == k % 2) {
			cout << k;
			return 0;
		}
	}
	cout << -1;
}
