#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	prev_permutation(v.begin(), v.end());
	for (int i = 0;i < n;i++) cout << v[i] << ' ';
}

