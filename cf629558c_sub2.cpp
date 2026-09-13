#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	char s;
	long long n;
	cin >> s >> n;
	if (n % 2 == 0) cout << s;
	else {
		if (s == 'A') cout << 'B';
		else cout << 'A';
	}
}
