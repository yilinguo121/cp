#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	char s;
	int n;
	cin >> s >> n;
	while (n--) {
		if (s == 'A') s = 'B';
		else s = 'A';
	}
	cout << s;
}
