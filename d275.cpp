#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		if (s[0] == s[s.size() - 1]) {
			cout << "NO LOOP\n";
			continue;
		}
		bool flag = 1;
		int cnt = 0;
		for (int i = 0;i < s.size();i++) {
			if (s[i] == ' ') cnt++;
			if (s[i] == ' ' and s[i - 1] == s[i + 1]) {
				cout << "NO LOOP\n";
				flag = 0;
				break;
			}
		}
		if (flag and cnt) cout << "LOOP\n";
		else if (flag and !cnt) cout << "NO LOOP\n";
	}
}

