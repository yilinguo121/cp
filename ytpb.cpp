#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	string s;
	while (n--) {
		string x;
		cin >> x;
		s += x;
	}
	string ss = s;
	reverse(s.begin(), s.end());
	if (ss == s) cout << "Yes";
	else cout << "No";
}

