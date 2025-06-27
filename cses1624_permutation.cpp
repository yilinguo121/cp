#include <bits/stdc++.h>
using namespace std;
string s[8];
bool check(vector<int> p) {
	bool left[17] = {}; //左上右下 x - y
	bool righ[17] = {}; //右上左下 x + y
	for (int i = 0;i < 8;i++) {
		if (s[i][p[i]] == '*' or left[i - p[i] + 8] or righ[i + p[i]]) return 0;
		left[i - p[i] + 8] = 1;
		righ[i + p[i]] = 1;
	}
	return 1;
}
int main() {
	vector<int> p;
	for (int i = 0;i < 8;i++) {
		cin >> s[i];
		p.push_back(i);
	}
	int ans = 0;
	do {
		if (check(p)) ans++;
	} while (next_permutation(p.begin(), p.end()));
	cout << ans;
}

