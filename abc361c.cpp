#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	sort (v.begin(), v.end());
	int m = 1e9;
	for (int i = 0, j = n - k - 1;j < n;j++, i++) {
		m = min(m, v[j] - v[i]);
	}
	cout << m;
}
