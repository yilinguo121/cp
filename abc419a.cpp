#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	cin >> s;
	if (s == "red") cout << "SSS";
	else if (s == "blue") cout << "FFF";
	else if (s == "green") cout << "MMM";
	else cout << "Unknown";
}

