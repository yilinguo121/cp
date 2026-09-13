#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO;
	string x1, y1, x2, y2;
	string a, b;
	while (cin >> a >> b) {
		int pos = a.find('.');
		x1 = a.substr(0, pos);
		y1 = a.substr(pos + 1);
		pos = b.find('.');
		x2 = b.substr(0, pos);
		y2 = b.substr(pos + 1);
		if (x1.size() != x2.size()) {
			cout << (x1.size() < x2.size() ? "<\n" : ">\n");
			return 0;
		}
		if (x1 != x2) {
			cout << (x1 < x2 ? "<\n" : ">\n");
			return 0;
		}
		while (y1.size() < y2.size()) y1 += "0";
		while (y2.size() < y1.size()) y2 += "0";
		if (y1 < y2) cout << "<\n";
		if (y1 > y2) cout << ">\n";
		if (y1 == y2) cout << "=\n";
	}
}
