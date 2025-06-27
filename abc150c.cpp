#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> p(n), q(n), v;
	for (int i = 0;i < n;i++) cin >> p[i];
	for (int i = 0;i < n;i++) cin >> q[i];
	for (int i = 1;i <= n;i++) v.push_back(i);
	int a = -1, b = -1;
	int i = 0;
	do {
		i++;
		bool A = 1, B = 1;
		for (int i = 0;i < n;i++) {
			if (v[i] != p[i]) A = 0;
			if (v[i] != q[i]) B = 0;
		}
		if (A) a = i;
		if (B) b = i;
		if (a != -1 and b != -1) break;
	}while (next_permutation(v.begin(), v.end()));
	cout << abs(a - b);
}
