#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> m(10), n(10);
	while (cin >> m[0]) {
		for (int i = 1;i < 10;i++) cin >> m[i];
		for (int i = 0;i < 10;i++) cin >> n[i];
		int a, b, s = 1e9;
		for (int i = 0;i < 10;i++) {
			for (int j = i;j < 10;j++) {
				if (m[i] + n[j] + (j - i) * 1000 < s) {
					a = i + 1;
					b = j + 1;
					s = m[i] + n[j] + (j - i) * 1000;
				}
			}
		}
		cout << a << ' ' << b << ' ' << s << '\n';
	}
}

