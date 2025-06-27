#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long t, n;
	cin >> t >> n;
	unsigned long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += 2 * t - __builtin_popcountll(t);
		uint64_t x = t;
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		t = x;
	}
	cout << ans;
}

