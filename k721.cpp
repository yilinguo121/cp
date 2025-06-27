#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int a, b;
	while (cin >> a >> b) cout << (b >= a or a <= 0 ? "能\n" : "不能\n");
}

