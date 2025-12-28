#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	bool ans = 1;
	for (int i = 100000000;i < n;i++) if (n % i == 0) {
		ans = 0;
		break;
	}
	cout << (ans ? "yes" : "no");
}
