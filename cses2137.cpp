#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
int main() {
	bitset<3000> st[3000];
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0;i < n;i++) {
		cin >> st[i];
		for (int j = 0;j < i;j++) {
			int t;
			t = (st[i] & st[j]).count();
			ans += t * (t - 1) / 2;
		}
	}
	cout << ans;
}

