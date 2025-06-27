#include<bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int a[94] = {};
	for (int i = 0;i < s.size();i++) {
		a[s[i] - 33]++;
	}
	for (int i = 0;i <= 93;i++) {
		char c = i + 33;
		while(a[i]) {
			cout << c;
			a[i]--;
		}
	}
}
