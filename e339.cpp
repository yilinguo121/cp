#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> v(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		v[i] += v[i - 1];
		cout << v[i] << ' ';
	}
}

