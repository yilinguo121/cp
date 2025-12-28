#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	int sum = 0;
	while (n--) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << (m >= sum ? "Yes\n" : "No\n");
}

