#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t, r;
	cin >> t >> r;
	cout << (bool)(t - (r + 1) * (t / (r + 1)));
}

