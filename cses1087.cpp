#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	cin >> s;
	int cnt = 0, a[4] = {}; //ACGT
	vector<char> ans;
	for (auto c : s) {
		if (c == 'A') {
			if (cnt == 3 and !a[0]) {
				ans.push_back('A');
				memset(a, 0, sizeof(a));
				cnt = 0;
			}
			else {
				if (!a[0]) cnt++;
				a[0] = 1;
			}
		}
		if (c == 'C') {
			if (cnt == 3 and !a[1]) {
				ans.push_back('C');
				memset(a, 0, sizeof(a));
				cnt = 0;
			}
			else {
				if (!a[1]) cnt++;
				a[1] = 1;
			}
		}
		if (c == 'G') {
			if (cnt == 3 and !a[2]) {
				ans.push_back('G');
				memset(a, 0, sizeof(a));
				cnt = 0;
			}
			else {
				if (!a[2]) cnt++;
				a[2] = 1;
			}
		}
		if (c == 'T') {
			if (cnt == 3 and !a[3]) {
				ans.push_back('T');
				memset(a, 0, sizeof(a));
				cnt = 0;
			}
			else {
				if (!a[3]) cnt++;
				a[3] = 1;
			}
		}
	}
	for (auto c : ans) cout << c;
	if (!a[0]) cout << 'A';
	else if (!a[1]) cout << 'C';
	else if (!a[2]) cout << 'G';
	else cout << 'T';
}

