#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	while (cin >> s) {
		int ans = 0;
		for (auto c : s) {
			if (c >= 'a' and c <= 'z') ans += c - 'a' + 1;
			else ans += c - 'A' + 27;
		}
		bool flag = 1;
		for (int i = 2;i < ans;i++) {
			if (!(ans % i)) {
				cout << "It is not a prime word.\n";
				flag = 0;
				break;
			}
		}
		if (flag) cout << "It is a prime word.\n";
	}
}

