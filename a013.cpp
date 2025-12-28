#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
map<char, int> mp = {
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000}
};
int f(string s) {
	int cnt = mp[s.back()];
	for (int i = 0;i < s.size() - 1;i++) {
		if (mp[s[i]] > mp[s[i + 1]]) cnt -= mp[s[i]];
		else cnt += mp[s[i]];
	}
	return cnt;
}
string get(int n) {
	if (!n) return "ZERO";
	string ans;
	vector<pair<int,string>> v = {
		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
		{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
		{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
	};
	for (auto [x, y] : v) {
		while (n >= x) {
			n -= x;
			ans += y;
		}
	}
	return ans;
}
int main() {
	string a, b;
	while (cin >> a) {
		if (a == "#") break;
		cin >> b;
		cout << get(abs(f(a) - f(b))) << '\n';
	}
}
