#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c - max({a, b, c}) <= max({a, b, c})) cout << "No";
	else if (a == b or b == c or a == c) cout << "Yes";
	else cout << "No";
}

