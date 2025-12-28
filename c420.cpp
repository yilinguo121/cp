#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	for (int i = 1;i < 2 * n;i += 2) cout << string(((2 * n - 1) - i) / 2, '_') << string(i, '*') << string(((2 * n - 1) - i) / 2, '_') << '\n';
}

