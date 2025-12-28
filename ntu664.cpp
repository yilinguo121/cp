#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<string> s;
int now;
int f();
int mul_div();
int dfs();
int f() {
	if (s[now] == "(") {
		now++;
		int t = dfs();
		now++;
		return t;
	}
	else {
		int t = stoi(s[now]);
		now++;
		return t;
	}
}
int mul_div() {
	int t = f();
	while (now < s.size() and (s[now] == "*" or s[now] == "/")) {
		now++;
		if (s[now - 1] == "*") t *= f();
		else t /= f();
	}
	return t;
}
int dfs() {
	int t = mul_div();
	while (now < s.size() and (s[now] == "+" or s[now] == "-")) {
		now++;
		if (s[now - 1] == "+") t += mul_div();
		else t -= mul_div();
	}
	return t;
}
int main() {
	IO
	string x;
	while (cin >> x) {
		s.push_back(x);
	}
	cout << dfs();
}
