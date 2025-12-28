#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> a(1000000001);
vector<int> b(1000000001);
int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) cin >> v[i];
	for (int i = 1;i <= 1000000000;i++) {
		if (i <= n) a[i] = v[i];
		b[i] = a[i] ^ b[i - 1];
	}
}

