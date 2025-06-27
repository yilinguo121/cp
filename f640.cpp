#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int f();
int g();
int h();
int f() {
	string c;
	cin >> c;
	if (c == "f") return 2 * f() - 3;
	if (c == "g") return 2 * g() - 3;
	if (c == "h") return 2 * h() - 3;
	return 2 * stoi(c) - 3;
}
int g() {
	string c;
	int a, b;
	cin >> c;
	if (c == "f") a = f();
	else if (c == "g") a = g();
	else if (c == "h") a = h();
	else a = stoi(c);
	cin >> c;
	if (c == "f") b = f();
	else if (c == "g") b = g();
	else if (c == "h") b = h();
	else b = stoi(c);
	return 2 * a + b - 7;
}
int h() {
	string c;
	int a, b, d;
	cin >> c;
	if (c == "f") a = f();
	else if (c == "g") a = g();
	else if (c == "h") a = h();
	else a = stoi(c);
	cin >> c;
	if (c == "f") b = f();
	else if (c == "g") b = g();
	else if (c == "h") b = h();
	else b = stoi(c);
	cin >> c;
	if (c == "f") d = f();
	else if (c == "g") d = g();
	else if (c == "h") d = h();
	else d = stoi(c);
	return 3 * a - 2 * b + d;
}
int main() {
	string c;
	cin >> c;
	if (c == "f") cout << f();
	if (c == "g") cout << g();
	if (c == "h") cout << h();
}
