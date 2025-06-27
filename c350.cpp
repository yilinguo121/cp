#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k, w;
	cin >> n >> k >> w;
	int t = n;
	while (t >= k) {
		t -= k;
		t += w;
		n += w;
	}
	cout << n;
}

