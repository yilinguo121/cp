#include <bits/stdc++.h>
using namespace std;
int main() {
	unsigned long long n;
	cin >> n;
	bitset<1000001> v;
	for (int i = 2;i * i <= 1000000;i++) {
		if (!v[i]) {
			for (int j = i + i;j <= 1000000;j += i) v[j] = 1;
		}
	}
	vector<unsigned long long> a;
	for (int i = 2;i <= 1000000;i++) {
		if (!v[i]) a.push_back(i);
	}
	long long ans = 0;
	for (int i = 0;i < a.size();i++) {
		if (a[i] * a[i] > n) break;
		for (int j = i + 1;j < a.size();j++) {
			if (a[i] * a[i] * a[j] > n) break;
			for (int k = j + 1;k < a.size();k++) {
				if (a[i] * a[i] * a[j] * a[k] * a[k] > n) break;
				ans++;
			}
		}
	}
	cout << ans;
}

