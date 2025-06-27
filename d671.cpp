#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		getline(cin, s);
		bool flag = 1;
		for (int i = 1;i <= 100;i++) if (i * i == s.size()) flag = 0;
		if (flag) cout << "INVALID\n";
		else {
			int n = sqrt(s.size());
			for (int i = 0;i < n;i++) {
				for (int j = i;j < s.size();j += n) cout << s[j];
			}
			cout << '\n';
		}
	}
}

