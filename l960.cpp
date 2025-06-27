#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	if (s == "Sunday") cout << 0 << '\n';
	else if (s == "Monday") cout << 1 << '\n';
	else if (s == "Tuesday") cout << 2 << '\n';
	else if (s == "Wednesday") cout << 3 << '\n';
	else if (s == "Thursday") cout << 4 << '\n';
	else if (s == "Friday") cout << 5 << '\n';
	else if (s == "Saturday") cout << 6 << '\n';
	else cout << "error\n";
}

