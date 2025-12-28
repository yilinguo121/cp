#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string a, b;
	cin >> a >> b;
	if (b == "Ocelot") cout << "Yes";
	else if (b == "Serval" and (a == "Serval" or a == "Lynx")) cout << "Yes";
	else if (b == "Lynx" and a == b) cout << "Yes";
	else cout << "No";
}

