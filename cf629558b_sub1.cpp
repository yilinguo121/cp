#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, x = 0;
		cin >> a;
		for (int i = 1;i < a;i *= 2, x++);
		cout << x << '\n';
	}
}

