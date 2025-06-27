#include <bits/stdc++.h>
using namespace std;
bool next(vector<int> &x) {
	int i = x.size() - 2;
	bool flag = 1;
	for (int k = 1;k < x.size();k++) if (x[k - 1] < x[k]) flag = 0;
	if (flag) return 0;
	while (x[i] >= x[i + 1]) {
		i--;
	}
	int j = i;
	while (x[j + 1] > x[i]) j++;
	swap(x[i], x[j]);
	reverse(x.begin() + i + 1, x.end());
	return 1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) cout << v[i] << ' ';
	cout << '\n';
	while (next(v)) {
		for (int i = 0;i < n;i++) cout << v[i] << ' ';
		cout << '\n';
	}
}

