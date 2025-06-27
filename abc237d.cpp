#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n;
	string s;
	cin >> n >> s;
	list<int> ls = {0};
	auto it = ls.begin();
	for (int i = 0;i < n;i++) {
		if (s[i] == 'L') {
			ls.insert(it, i + 1);
			it--;
		}
		else {
			ls.insert(next(it), i + 1);
			it++;
		}
	}
	for (auto x : ls) cout << x << ' ';
}

