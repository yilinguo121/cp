#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<string, int> mp;
	while (n--) {
		string s;
		cin >> s;
		mp[s]++;
		cout << s;
		if (mp[s] > 1) cout << '(' << mp[s] - 1 << ')';
		cout << '\n';
	}
}

