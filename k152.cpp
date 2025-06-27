#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	cout << '|' << a;
	for (int i = 0;i < 10 - a.size();i++) cout << ' ';
	cout << '|';
	for (int i = 0;i < 10 - b.size();i++) cout << ' ';
	cout << b << '|';
}

