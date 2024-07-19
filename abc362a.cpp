#include<bits/stdc++.h>
using namespace std;
int main() {
	int r, g, b;
	cin >> r >> g >> b;
	string s;
	cin >> s;
	if (s == "Red") {
		cout << min(g, b) << '\n';
	}
	else if (s == "Green") {
		cout << min(r, b) << '\n';
	}
	else {
		cout << min(r, g) << '\n';
	}
}
