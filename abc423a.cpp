#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int x, c;
	cin >> x >> c;
	cout << x / (1000 + c) * 1000;
}

