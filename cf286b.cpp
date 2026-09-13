#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v(2 * n);
	for (int i = 1;i <= n;i++) v[i] = i;
	for (int k = 2, head = 1;k <= n;k++, head++) for (int i = n / k * k;i >= 0;i -= k) v[min(n, i + k) + head] = v[i + head];
	for (int i = 0;i < n;i++) cout << v[i + n] << ' ';
}

