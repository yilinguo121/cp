#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		cout << (((n - b) % 2 == 0) and (a <= b or ((b - a) % 2 == 0)) ? "Yes\n" : "No\n");
	}
}

