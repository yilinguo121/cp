#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
string s;
int i = 0;
int c() {
	if (s[i] == '!') {
		i++;
		return !c();
	}
	else return s[i++] - '0';
}
int b() {
	int l = c();
	while (i < s.size() and s[i] == '*') {
		i++;
		l &= c();
	}
	return l;
}
int a() {
	int l = b();
	while (i < s.size() and s[i] == '+') {
		i++;
		l |= b();
	}
	return l;
}
int main() {
	IO
	while (cin >> s) {
		if (s == "END") break;
		i = 0;
		cout << a() << '\n';
	}
}
