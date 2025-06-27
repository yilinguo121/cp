#include<bits/stdc++.h>
using namespace std;
#define int long long
struct s {
	string s;
	int a;
	int b;
	int m;
};
signed main() {
	int n;
	s f;
	s j;
	f.m = -100000000;
	while (cin >> n) {
		for (int i = 0;i < n;i++) {
			cin >> j.s >> j.a >> j.b;
			j.m = j.a * 5 + j.b;
			if (j.m > f.m) {
				f.m = j.m;
				f.a = j.a;
				f.b = j.b;
				f.s = j.s;

			}
		}
		string t;
		cin >> t;
		cout << f.s << ' ' << f.m << ' ' << f.a << ' ' << f.b << '\n';
	}
}
