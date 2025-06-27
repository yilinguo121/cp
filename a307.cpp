#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n;
	while (cin >> n) {
		if (n < 0) cout << "-";
		string s = to_string(abs(n));
		reverse(s.begin(), s.end());
		s = to_string(stoi(s));
		cout << s << '\n';
	}
}

