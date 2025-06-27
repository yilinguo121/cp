#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int t;
	cin >> t;
	int n = s.size();
	while (t--) {
		int x;
		cin >> x;
		if (x == 0) {
			for (int i = 1;i < n;i += 2) swap(s[i], s[i - 1]);
		}
		if (x == 1) {
			for (int i = 1;i < n;i += 2) {
				if (s[i] < s[i - 1]) swap(s[i], s[i - 1]);
			}
		}
		if (x == 2) {
			string a = s;
			for (int i = 0, j = 1;j < n;i++, j += 2) {
				s[j - 1] = a[i];
				s[j] = a[i + n / 2];
			}
		}
	}
	cout << s;
}

