#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << (a == b ? 0 : (lcm(a, b) == a or lcm(a, b) == b ? 1 : 2)) << '\n';
	}
}

