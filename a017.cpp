#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
vector<string> s;
int now;
ll f();
ll mul_div();
ll dfs();
ll f() {
	if (s[now] == "(") {
		now++;
		ll t = dfs();
		now++;
		return t;
	}
	else {
		ll t = stoll(s[now]);
		now++;
		return t;
	}
}
ll mul_div() {
	ll t = f();
	while (now < (int)s.size() and (s[now] == "*" or s[now] == "/" or s[now] == "%")) {
		string op = s[now++];
		if (op == "*") t *= f();
		else if (op == "/") t /= f();
		else t %= f();
	}
	return t;
}
ll dfs() {
	ll t = mul_div();
	while (now < (int)s.size() and (s[now] == "+" or s[now] == "-")) {
		string op = s[now++];
		if (op == "+") t += mul_div();
		else t -= mul_div();
	}
	return t;
}
int main() {
	IO
	string line;
	while (getline(cin, line)) {
		if (line.size() == 0) continue;
		s.clear();
		stringstream ss(line);
		string x;
		while (ss >> x) s.push_back(x);
		now = 0;
		cout << dfs() << '\n';
	}
}
