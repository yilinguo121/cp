#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		int size = s.size();
		int a[30] = {};
		for (int i = 0;i < s.size();i++) {
			if (s[i] >= 'a' and s[i] <= 'z') {
				int j = s[i] - 'a';
				a[j]++;
			}
			else if (s[i] >= 'A' and s[i] <= 'Z') {
				int j = s[i] - 'A';
				a[j]++;
			}
			else {
				size--;
			}
		}
		int p = 0, q = 0;
		for (int i = 0;i < 26;i++) {
			if (a[i] != 0 and a[i] % 2 == 0) {
				p++;
			}
			if (a[i] % 2 == 1) {
				q++;
			}
		}
		if (size % 2 == 0) {
			if (q == 0) {
				cout << "yes !" << '\n';
			}
			else {
				cout << "no..." << '\n';
			}
		}
		else {
			if (q == 1) {
				cout << "yes !" << '\n';
			}
			else {
				cout << "no..." << '\n';
			}
		}
	}
}
