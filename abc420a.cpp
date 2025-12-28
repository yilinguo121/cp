#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int f(int x) {
	while (x > 12) x -= 12;
	return x;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << f(a + b);
}
