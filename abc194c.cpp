#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	int square = 0;
	int sum = 0;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		square += (a * a);
		sum += a;
	}
	cout << square * n - sum * sum;
}

