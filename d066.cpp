#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int h, m;
	cin >> h >> m;
	cout << ((h >= 7 and h < 17) and (!(h == 7 and m < 30)) ? "At School" : "Off School");
}

