#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	int a = 1, b = 1;
	for (int i = 2;i <= n;i++) tie(a, b) = make_pair(b, (a + b) % 1000000007);
	cout << b;
}
