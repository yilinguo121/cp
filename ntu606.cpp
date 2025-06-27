#include <bits/stdc++.h>
using namespace std;
vector<int> v(25);
int n, k;
bool flag = 0;
void f(int pos, int sum) {
	if (sum == k) {
		flag = 1;
		return;
	}
	if (sum > k or pos >= n) return;
	f(pos + 1, sum + v[pos]);
	f(pos + 1, sum);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	f(0, 0);
	if (flag) cout << "YES\n";
	else cout << "NO\n";
}

