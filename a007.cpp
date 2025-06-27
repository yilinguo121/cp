#include <bits/stdc++.h>
using namespace std;
bitset<2147483650> v = {};
int main() {
	int a, d, n;
	cin >> a >> d >> n;
	v[1] = 1;
	for (int i = 2;i <= 2147483647;i++) {
		if (!v[i]) {
			for (int j = i + i;j <= 2147483647;j += i) {
				v[j] = 1;
			}
		}
	}
	int x;
	while (cin >> x) {
		if (v[x]) cout << "非質數\n";
		else cout << "質數\n";
	}
}
