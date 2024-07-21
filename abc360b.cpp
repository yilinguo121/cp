#include<bits/stdc++.h>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	for (int i = 1;i < s.size();i++) {
		for(int j = 0;j < i;j++) {
			string ans;
			for (int k = j;k < s.size();k += i) {
				ans += s[k];
			}
			if (ans == t) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}
