#include <bits/stdc++.h>
using namespace std;
/*
0 1 2
3 4 5
6 7 8
*/
vector<int> v(9);
bool f(int i, int j, int k) {
	if (v[i] == v[j] and (v[i] == v[j] and v[j] != v[k])) return 0;
	return 1;
}
int main() {
	for (int i = 0;i < 9;i++) cin >> v[i];
	sort(v.begin(), v.end());
	double ans = 0, sum = 0;
	do {
		if (f(0, 1, 2) and f(3, 4, 5) and f(6, 7, 8) and f(0, 3, 6) and f(1, 4, 7) and f(2, 5, 8) and f(0, 4, 8) and f(2, 4, 6)) ans++;
		sum++;
	}while (next_permutation(v.begin(), v.end()));
	cout << fixed << setprecision(-18) << ans / sum;
}
