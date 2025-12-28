#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	while (n--) {
		char x;
		cin >> x;
		if (x >= 'A' and x <= 'D') cout << "Basic Syntax and Function Calls\n";
		else if (x >= 'E' and x <= 'H') cout << "Basic algorithms and data structures\n";
		else cout << "Insanely difficult advanced algorithms\n";
	}
}

